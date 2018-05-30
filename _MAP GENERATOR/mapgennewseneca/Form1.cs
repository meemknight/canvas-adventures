using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Timers;
enum type
{
    air = '0',
    dirt = 'a',
    grass = 'b',
    stone = 'c',
    plants='d',
    sand,
    sand_ruby,
    sandstone,
    woodenplank,
    stonebricks,
    clay,
    wood = 'w',
    leafs,
    copper,
    iron='m',
    gold='n',
    copperblock,
    ironblock,
    goldblock,
    bricks,
    snowblock,
    iceblock,
    rubbyblock,
    platform,
    workbench,
    glass,
    furnace,
    painting,
    sappling,
    snow_gem,
    ice_gem_block,
    dirt_wall,
    stone_wall,
    wodden_wall,
    sandstone_wall,
    brick_wall,
    glass_wall,
    copper_wall,
    iron_wall,
    gold_wall,
    snow_wall,
    sand_wall,
    stonebricks_wall,
    rubby_wall,
    heroglyphics,
    ice_gem_wall
};
enum directions
{
    fastUp,
    up,
    slowUp,
    fastDown,
    down,
    slowDown,


};


namespace mapgennewseneca
{
    public partial class Form1 : Form
    {
        int seed = unchecked(DateTime.Now.Ticks.GetHashCode());
        int seedmul = 1;
        int val = 1;
        public int RandomNumber(int min, int max)
        {
            for (int i = 0; i < 127; i++)
            {
                seedmul++;
                val = (seed * seedmul) % (max - min) + min;

            }
            seed++;
            return Math.Abs(val);

        }

        int[,] world = new int[gamelenght, gameheight];
        int[,] nummountains = new int[2, 2];
        const int gamelenght = 720;
        const int gameheight = 320;
        int grasslevel = 110;
        int maxmountainlevel = 60;
        int updatefreq = 20;



        //variabele gay ale lui luta     
        int height_ = 150;
        int direction_ = 0;
        int blocksUntilUpdate_ = 0;
        int stonePadding_ = 10;



        public Form1()
        {
            InitializeComponent();
            textBox1.Text = ("110");
            textBox3.Text = ("60");
            textBox4.Text = ("20");
        }

        void put_block(int x, int y, int bltype)
        {
            if (x >= 0 && x < gamelenght && y >= 0 && x < gamelenght)
            {
                world[x, y] = bltype;
            }
        } //places a single block in  specified place


        public void channgeDirection()
        {
            int result = RandomNumber(0, 100);
            if (result < 10)
            {
                direction_ = (int)directions.fastUp;
            }
            else
            if (result < 20)
            {
                direction_ = (int)directions.fastDown;
            }
            else
            if (result < 40)
            {
                direction_ = (int)directions.up;
            }
            else
            if (result < 60)
            {
                direction_ = (int)directions.down;
            }
            else
            if (result < 80)
            {
                direction_ = (int)directions.slowDown;
            }
            else
            if (result < 100)
            {
                direction_ = (int)directions.slowUp;
            }

            blocksUntilUpdate_ = RandomNumber(0, updatefreq);
        }

        public bool getRandomPercent(int chance)
        {
            int result = RandomNumber(0, 100);
            if (result < chance)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        public void PutRow(int x)
        {
            if (blocksUntilUpdate_ <= 0)
            {
                channgeDirection();
            }


            if (height_ < maxmountainlevel)
            {
                if (getRandomPercent(50))
                {
                    direction_ = (int)directions.fastDown;
                }
                else
                {
                    direction_ = (int)directions.down;
                }
                blocksUntilUpdate_ = RandomNumber(0, updatefreq);
            }

            if (height_ > grasslevel)
            {
                if (getRandomPercent(50))
                {
                    direction_ = (int)directions.fastUp;
                }
                else
                {
                    direction_ = (int)directions.up;
                }
                blocksUntilUpdate_ = RandomNumber(0, updatefreq);
            }



            if (direction_ == (int)directions.fastUp)
            {
                if (getRandomPercent(70))
                    height_ -= RandomNumber(0, 4);
            }
            if (direction_ == (int)directions.up)
            {
                if (getRandomPercent(50))
                    height_ -= RandomNumber(0, 3);
            }
            if (direction_ == (int)directions.slowUp)
            {
                if (getRandomPercent(10))
                    height_ -= RandomNumber(0, 2);
            }
            if (direction_ == (int)directions.fastDown)
            {
                if (getRandomPercent(70))
                    height_ += RandomNumber(0, 4);
            }
            if (direction_ == (int)directions.down)
            {
                if (getRandomPercent(50))
                    height_ += RandomNumber(0, 3);
            }
            if (direction_ == (int)directions.slowDown)
            {
                if (getRandomPercent(10))
                    height_ += RandomNumber(0, 2);
            }


            blocksUntilUpdate_--;

            for (int i = height_; i < gameheight; i++)
            {
                world[x, i] = (int)type.dirt;
            }
            for (int i= height_+stonePadding_+RandomNumber(0,3);i< gameheight;i++)
            {
                world[x, i] = (int)type.stone;
            }
        }




        private void button1_Click(object sender, EventArgs e)
        {
            int grasslvlint = Convert.ToInt32(textBox1.Text);//converts string value of textBox1 to int
            int maxmountainlvlint = Convert.ToInt32(textBox3.Text);//converts string value of textBox3 to int
            int updatefreqint = Convert.ToInt32(textBox4.Text);//converts string value of textBox4 to int

            grasslevel = grasslvlint;
            maxmountainlevel = maxmountainlvlint;
            updatefreq = updatefreqint;
            blocksUntilUpdate_ = RandomNumber(0, 100);


            StreamWriter File = new StreamWriter("map.txt");
            label1.Text = (RandomNumber(0, 100).ToString());


            for (int x = 0; x < gamelenght; x++)
            {
                for (int y = 0; y < gameheight; y++)//change gameheight to grasslevel
                {
                    world[x, y] = (int)type.air;
                }
            }

            /*
            for (int x = 0; x < gamelenght; x++)
            {
                for (int y = grasslevel; y < stonelevel; y++)
                {
                    world[x, y] = (int)type.dirt;
                }
            }
            for (int x = 0; x < gamelenght; x++)
            {
                for (int y = stonelevel; y < gameheight; y++)
                {
                    world[x, y] = (int)type.stone;
                }
            }
            */
            direction_ = (RandomNumber(0, 6));
            for (int i = 0; i < gamelenght; i++)
            {
                PutRow(i);
            }


            ///------------------------------------MOUNTAINS------------------------------///
            //int yy;
            //int xx;
            //Random rndmnt = new Random();//am schimbat metoda de generare pozitii random pentru varfurile muntilor pentru a functiona in for loops
            //Random tmp1 = new Random();
            //for (int a=0; a<=nrofsountains;a++)
            //{
            //    yy = rndmnt.Next(maxmountainlevel, grasslevel);
            //    xx= rndmnt.Next(0, gamelenght);

            //    int h = yy;
            //    int z = grasslevel;
            //    while (yy != z)  
            //    {
            //        put_block(xx, yy,(int)type.stone);
            //        for (int i = xx-(yy-h);i<xx; i++)
            //        {
            //            put_block(i,yy, (int)type.stone);
            //        }
            //        for (int i = xx + 1; i <= xx + (yy - h); i++)
            //        {
            //            put_block(i, yy, (int)type.stone);
            //        }


            //            yy++;

            //    }

            //}


            for (int y = 0; y < gameheight; y++)//scrie in fisier tot
            {
                for (int x = 0; x < gamelenght; x++)

                {
                    File.Write((Char)world[x, y]);
                }
                File.Write("\n");
            }
            File.Close();
        }









        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
