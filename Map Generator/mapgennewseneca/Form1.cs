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
    plants = 'd',
    sand= 'e',
    sand_ruby='z',
    sandstone = 'A',
    woodenplank ='f',
    stonebricks='g',
    clay = 'h',
    wood = 'w',
    leafs = 'j',
    copper = 'k',
    iron = 'm',
    gold = 'n',
    copperblock ='u',
    ironblock='t',
    goldblock,
    bricks,
    snowblock,
    iceblock,
    rubbyblock = 'B',
    platform,
    workbench,
    glass,
    furnace,
    painting,
    sappling,
    snow_gem,
    ice_gem_block,
    wodden_door,
    bottle,
    table,
    wardrobe,
    book_shelf,
    ice_bricks,
    ice_table,
    ice_wardrobe,
    ice_book_shelf,
    ice_platform,
    sand_table,
    sand_wardrobe,
    sand_book_shelf,
    sand_platform,
    chest,
    ice_chest,
    sand_chest,
    dungeon_chest,
    dungeon_block,
    dungeon_table,
    dungeon_wordrobe,
    dungeon_bookshelf,
    dungeon_platform,
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
    ice_gem_wall,
    wodden_stone_wall,
    ice_brick_wall,
    dungeon_wall,
    last_block
}
enum wall_type
{
    air='0',
    dirt_wall='a',
    stone_wall='b',
    wodden_wall='c',
    brick_wall='d',
    glass_wall='e',
    copper_wall='f',
    iron_wall='g',
    gold_wall='h',
    snow_wall='i',
    sand_wall='j',
    stonebricks_wall='k',
    sandstone_wall='l',
    rubby_wall='m',
    heroglyphics='n',
    ice_gem_wall='o',
    wodden_stone_wall='p',
    ice_brick_wall='q',
    dungeon_wall='r'
}
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
        StreamWriter MapFile;
        StreamWriter WallsFile;
        int seed = unchecked(DateTime.Now.Ticks.GetHashCode());
        int seedmul = 1;
        int val = 1;

        //debug



        #region RANDOM_GENERATOR
        public int RandomNumber(int min, int max)
        {
            for (int i = 0; i < 31; i++)
            {
                seedmul++;
                val = (seed * seedmul) % (max - min) + min;
            }
            seed++;
            return Math.Abs(val);

        }
        #endregion

        #region RANDOM_PERCENT
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
        #endregion

        #region DECLARARE_VAR
        int[,] world = new int[gamelenght, gameheight];
        int[,] walls = new int[gamelenght, gamelenght];
        int[,] nummountains = new int[2, 2];
        const int gamelenght = 840;
        const int gameheight = 320;
        int grasslevel = 110;
        int maxmountainlevel = 60;
        int updatefreq = 20;
      



        //variabele gay ale lui luta  -XD   
        int height_ = 150;
        int direction_ = 0;
        int blocksUntilUpdate_ = 0;
        int stonePadding_ = 10;
        #endregion
       
        #region FORM_1_START
        public Form1()
        {
            InitializeComponent();
            textBox1.Text = ("110");
            textBox3.Text = ("60");
            textBox4.Text = ("20");
        }
        #endregion

        #region BLOCK_PLACERS
        void put_block(int x, int y, int bltype) //places a single block at a given place
        {
            if (x >= 0 && x < gamelenght && y >= 0 && y < gameheight)
            {
                world[x, y] = bltype;
            }
        }
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
            for (int i = height_ + stonePadding_ + RandomNumber(0, 3); i < gameheight; i++)
            {
                world[x, i] = (int)type.stone;
            }
        }
        public void PutWalls()
        {
            for (int y=0;y<gameheight;y++)
            {
                
                for(int x=0;x<gamelenght;x++)
                {              
                    if(world[x,y]==(int)type.dirt)
                    {
                        walls[x, y] = (int)wall_type.dirt_wall;
                    }
                    else
                    if(world[x, y] == (int)type.stone || world[x,y]==(int)type.iron || world[x, y] == (int)type.copper || world[x, y] == (int)type.gold)
                    {
                        walls[x,y] = (int)wall_type.stone_wall;
                    }
                    else
                    if (world[x, y] == (int)type.air)
                    {
                        walls[x, y] = (int)wall_type.air;
                    }


                }
                     
        }


        }
        #endregion

        #region PATCH_PLACERS
        public void putPatch(int x, int y, int size, int blocktype) //creates patches of certain blocks at a given place
        {
            //cadranul 1 trig
            int patchLength = RandomNumber(size - 1, size + 2);
            int patchHeigth = y;

            while (patchLength > 0)
            {
                for (int i = x; i <= patchLength + x; i++)
                {
                    put_block(i, patchHeigth, blocktype);
                }
                patchHeigth--;
                patchLength -= RandomNumber(0, 3);
            }
            //cadranul 2 trig
            patchLength = RandomNumber(size - 1, size + 2);
            patchHeigth = y;
            while (patchLength > 0)
            {
                for (int i = x-patchLength; i <= x; i++)
                {
                    put_block(i, patchHeigth, blocktype);
                }
                patchHeigth--;
                patchLength -= RandomNumber(0, 3);
            }
            //cadranul 3 trig
            patchLength = RandomNumber(size - 1, size + 2);
            patchHeigth = y;
            while (patchLength > 0)
            {
                for (int i = x - patchLength; i <= x; i++)
                {
                    put_block(i, patchHeigth, blocktype);
                }
                patchHeigth++;
                patchLength -= RandomNumber(0, 3);
            }
            //cadranul 4 trig
            patchLength = RandomNumber(size - 1, size + 2);
            patchHeigth = y;
            while (patchLength > 0)
            {
                for (int i = x; i <= patchLength + x; i++)
                {
                    put_block(i, patchHeigth, blocktype);
                }
                patchHeigth++;
                patchLength -= RandomNumber(0, 3);
            }

        }
        public void createGrasshole(int numberOfHoles)
        {
            for (int i = 0; i < numberOfHoles; i++)
            {
                putPatch(RandomNumber(0, gamelenght), maxmountainlevel + 20, 18, (int)type.air);

            }
        }
        public void createClayPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                int tempx = RandomNumber(0, gamelenght-1);
                int tempy = 0;
                for (int y = 0; world[tempx, y] != (int)type.dirt && world[tempx,y]!=(int)type.stone; y++)
                {
                    tempy = y;

                }
                int ypos = tempy + RandomNumber(5,15);
                putPatch(tempx, ypos, RandomNumber(1, 3), (int)type.clay);
                putPatch(tempx + RandomNumber(2, 4), ypos, RandomNumber(1, 3), (int)type.clay);
            }
        }
        public void createStonePatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                int tempx = RandomNumber(0, gamelenght - 1);
                int tempy = 0;
                for (int y = 0; world[tempx, y] != (int)type.dirt && world[tempx, y] != (int)type.stone; y++)
                {
                    tempy = y;
                }

                int ypos = tempy + RandomNumber(2, 3);
                putPatch(tempx, ypos, RandomNumber(1, 2), (int)type.stone);

            }
        }
        public void createDirtPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght-1), RandomNumber(200, 270), 14, (int)type.dirt);
            }
        }
        public void createIronPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(200, 270), 4, (int)type.iron);
            }
        }
        public void createCopperPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(200, 270), 7, (int)type.copper);
            }
        }
        public void createGoldPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(200, 270), 2, (int)type.gold);
            }
        }
        public void createRubyPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(200, 270), 1, (int)type.rubbyblock);
            }
        }
        public void createCavePatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(200, 270), 20, (int)type.air);
            }
        }



        #endregion


        private void button1_Click(object sender, EventArgs e)
        {
            int grasslvlint = Convert.ToInt32(textBox1.Text);//converts string value of textBox1 to int
            int maxmountainlvlint = Convert.ToInt32(textBox3.Text);//converts string value of textBox3 to int
            int updatefreqint = Convert.ToInt32(textBox4.Text);//converts string value of textBox4 to int

            grasslevel = grasslvlint;
            maxmountainlevel = maxmountainlvlint;
            updatefreq = updatefreqint;
            blocksUntilUpdate_ = RandomNumber(0, 100);

            

            if (radioButton1.Checked)
            {
                MapFile =  new StreamWriter("map1\\map.txt");
                WallsFile =  new StreamWriter("map1\\walls.txt");
            }
            

            if(radioButton2.Checked)
            {
                MapFile = new StreamWriter("map2\\map.txt");
                WallsFile = new StreamWriter("map2\\walls.txt");
            }
            if(radioButton3.Checked)
            {
               MapFile = new StreamWriter("map3\\map3.txt");
               WallsFile = new StreamWriter("map3\\walls3.txt");
            }
            
            label1.Text = (RandomNumber(0, 100).ToString());


            for (int x = 0; x < gamelenght; x++)
            {
                for (int y = 0; y < gameheight; y++)//change gameheight to grasslevel
                {
                    world[x, y] = (int)type.air;
                }
            }
            direction_ = (RandomNumber(0, 6));
            for (int i = 0; i < gamelenght; i++)
            {
                PutRow(i);
            }

            
            


            
            createGrasshole(8);
            createClayPatch(25);
            createDirtPatch(13);
            createStonePatch(30);
            createIronPatch(50);
            createCopperPatch(50);
            createGoldPatch(50);
            createRubyPatch(25);
            createCavePatch(12);

            PutWalls();
            for (int y = 0; y < gameheight; y++)//scrie in fisierul walls.txt tot
            {
                for (int x = 0; x < gamelenght; x++)

                {
                    WallsFile.Write((Char)walls[x, y]);
                }
                WallsFile.Write("\n");
            }
            WallsFile.Close();
            for (int y = 0; y < gameheight; y++)//scrie in fisierul world.txt tot
            {
                for (int x = 0; x < gamelenght; x++)

                {
                    MapFile.Write((Char)world[x, y]);
                }
                MapFile.Write("\n");
            }
            MapFile.Close();

            
        }



        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
