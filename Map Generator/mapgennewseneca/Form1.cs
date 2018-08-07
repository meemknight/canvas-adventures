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
    iron = 'l',
    gold = 'm',
    copperblock ='u',
    ironblock='t',
    goldblock,
    bricks,
    snowblock='v',
    iceblock,
    rubbyblock = 'B',
    platform,
    workbench,
    glass,
    furnace,
    painting,
    sappling,
    snow_gem ='D',
    ice_gem_block='D',
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
        StreamWriter StatsFile;
        int seed = unchecked(DateTime.Now.Ticks.GetHashCode());
        int seedmul = 1;
        int val = 1;
        int xposition = gamelenght / 2;
        int yposition = 1;


        public int SpawnPointYAxis()
        {
            while(true)
            {
                if (world[xposition,yposition] != (int)type.air)
                {

                    break;
                }
                yposition++;
            }
            yposition -= 2;
            
            return  (yposition * 32)- (2*32);
        }

        int[] playerstatsvalue = new int[99]
    {         12800,0,12800,0,100,1,0,0,0,
              //xpos,ypos, xpawn,yspawn
              0,20,1,
              0,1,1,
              0,2,1,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
              1,0,0,
      };

        

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
        int height_ = 150;//150
        int direction_ = 0;
        int blocksUntilUpdate_ = 0;
        int stonePadding_ = 10;
        #endregion
       
        #region FORM_1_START
        public Form1()
        {
            InitializeComponent();

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


            for (int i = height_-7; i < gameheight; i++)
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
                    if (world[x, y] == (int)type.sand)
                    {
                        walls[x, y] = (int)wall_type.sand_wall;
                    }
                    else
                    if (world[x, y] == (int)type.snowblock)
                    {
                        walls[x, y] = (int)wall_type.snow_wall;
                    }
                    else
                    if (world[x, y] == (int)type.air)
                    {
                        walls[x, y] = (int)wall_type.air;
                    }
                }
                     
            }


        }
        public void PutGrass()
        {
            for (int x = 0; x < gamelenght - 1; x++)
            {
                for (int y = 0; y < gameheight  - 1; y++)
                {
                    if (world[x, y] == (int)type.dirt)
                    {
                        world[x, y] = (int)type.grass;
                        break;
                    }
                    else
                    {

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
                putPatch(RandomNumber(0, gamelenght), maxmountainlevel + 20, RandomNumber(5,12), (int)type.air);

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
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(250, 290), RandomNumber(2,4), (int)type.iron);
            }
        }
        public void createCopperPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(250, gameheight), RandomNumber(2,3), (int)type.copper);
            }
        }
        public void createGoldPatch(int numberOfPatches)
        {
            for (int i = 0; i < numberOfPatches; i++)
            {
                putPatch(RandomNumber(0, gamelenght - 1), RandomNumber(260, gameheight), RandomNumber(1, 3), (int)type.gold);
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

        #region BIOME_MANAGER
        public void Biomize()
        {
            int LR = RandomNumber(0, 2);
            int snowStart = 0;
            int snowEnd = 0;
            int desertStart = 0;
            int desertEnd = 0;
           
            if (LR==0)
            {
                label3.Text = "Snow Left / Desert Right";
                snowStart = 150;
                snowEnd = 300;
                desertStart = 540;
                desertEnd = 690;
            }
            else
            {
                label3.Text = "Desert Left / Snow Right ";
                snowStart = 540;
                snowEnd = 690;
                desertStart = 150;
                desertEnd = 300;
            }

            for (int y = 0; y < gameheight - 1; y++)
            {
                for (int x = snowStart; x < snowEnd - 1; x++)
                {
                    if (world[x, y] == (int)type.dirt ||world[x,y]==(int)type.grass)
                    {
                        world[x, y] = (int)type.snowblock;  
                    }
                    else
                    if (world[x, y] == (int)type.clay)
                    {
                        world[x, y] = (int)type.iceblock;
                    }
                    else
                    if(world[x,y]==(int)type.copper)
                    {
                        world[x, y] = (int)type.ice_gem_block;
                    }
                    else
                    {

                    }

                }

            }
            for (int y = 0; y < gameheight - 1; y++)
            {
                for (int x = desertStart; x < desertEnd - 1; x++)
                {
                    if (world[x, y] == (int)type.dirt|| world[x, y] == (int)type.grass)
                    {
                        world[x, y] = (int)type.sand;
                    }
                    if (world[x, y] == (int)type.copper)
                    {
                        world[x, y] = (int)type.sand_ruby;
                    }
                    else
                    {

                    }
                }

            }
        }



        #endregion

        #region StatsFileWriter
        public void statsFileWriter()
        {
            int stfilecharcounter = 0;
            for (int i = 1; i <= 9; i++)
            {
                StatsFile.Write(playerstatsvalue[stfilecharcounter]);
                StatsFile.Write(' ');
                stfilecharcounter++;
            }
            StatsFile.Write("\n");
            for (int i = 1; i <= 30; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    StatsFile.Write(playerstatsvalue[stfilecharcounter]);
                    StatsFile.Write(' ');
                    stfilecharcounter++;
                }
                StatsFile.Write("\n");
            }
            StatsFile.Close();
        }
        #endregion


        private void button1_Click(object sender, EventArgs e)
        {

            int grasslvlint = 110;
            int maxmountainlvlint = 60;
            int updatefreqint = 20;



            if (comboBox1.SelectedIndex == 0)//Rough
            {
                maxmountainlvlint = 60;
                updatefreqint = 80;
            }
            else
            if(comboBox1.SelectedIndex ==1)//normal
            {
                maxmountainlvlint = 60;
                updatefreqint = 20;
            }
            if (comboBox1.SelectedIndex == 2)//smooth
            {
                maxmountainlvlint = 70;
                updatefreqint = 8;
            }
            else
            {
                maxmountainlvlint = 60;
                updatefreqint = 20;
            }
            //int maxmountainlvlint = Convert.ToInt32(textBox3.Text);//converts string value of textBox3 to int
            //int updatefreqint = Convert.ToInt32(textBox4.Text);//converts string value of textBox4 to int

            grasslevel = grasslvlint;
            maxmountainlevel = maxmountainlvlint;
            updatefreq = updatefreqint;
            blocksUntilUpdate_ = RandomNumber(0, 100);

            

            if (radioButton1.Checked)
            {
                MapFile =  new StreamWriter("map1\\map.txt");
                WallsFile =  new StreamWriter("map1\\walls.txt");
                StatsFile = new StreamWriter("map1\\playerstats.txt");
            }
            
            if(radioButton2.Checked)
            {
                //MapFile = new StreamWriter("map2\\map.txt");
                //WallsFile = new StreamWriter("map2\\walls.txt");
                //StatsFile = new StreamWriter("map2\\playerstats.txt");
                MapFile = new StreamWriter("C:\\Users\\david\\Documents\\GitHub\\Canvas-Adventures\\Canvas Adventures 0.14\\bin\\Release\\map2\\map.txt");
                WallsFile = new StreamWriter("C:\\Users\\david\\Documents\\GitHub\\Canvas-Adventures\\Canvas Adventures 0.14\\bin\\Release\\map2\\walls.txt");
                StatsFile = new StreamWriter("C:\\Users\\david\\Documents\\GitHub\\Canvas-Adventures\\Canvas Adventures 0.14\\bin\\Release\\map2\\playerstats.txt");
            }
            if (radioButton3.Checked)
            {
               MapFile = new StreamWriter("map3\\map.txt");
               WallsFile = new StreamWriter("map3\\walls.txt");
               StatsFile = new StreamWriter("map3\\playerstats.txt");
            }
            
            //debug counter
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
            createCopperPatch(60);
            createGoldPatch(60);
            Biomize();
            PutGrass();
            PutWalls();
            createCavePatch(12);


            playerstatsvalue[1] = SpawnPointYAxis();
            playerstatsvalue[3] = SpawnPointYAxis();
            label5.Text = SpawnPointYAxis().ToString();

            if (radioButton1.Checked || radioButton2.Checked || radioButton3.Checked)
            {
                #region SE_SCRIE_IN_FISIERE

                statsFileWriter();

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
                label6.Text = "World Generated";
                #endregion
                
                
                Application.Exit();                

            }
            else
            {
                label6.Text = "Please select a world slot";
            }


        }












        
        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
        private void label2_Click(object sender, EventArgs e)
        {

        }
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        
    }
}
