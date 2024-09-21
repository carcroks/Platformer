using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Platformer
{
    internal class Character
    {
        public int x;
        public int y;

        private int speed = 4;
        private int speedBoost = 1;
        private int jumpHeight = 40;

        public float speedX;
        public float speedY;

        float GroundFriction = 0.70f;


        float gravity = 0.70f;

        float fallingIncrease = 1.5f;

        private Boolean bhopForcer = false;

        private Boolean falling = false;

        private Boolean inAir = false;


        private MainWindow w;


        public Character(MainWindow w)
        {
            this.w = w;

            //x = w.field.Width/2;
            x = 500;
            y = 0;

            speedX = 0;
            speedY = 0;
        }

        public void Update()
        {
            //right and left movement
            if (w.LeftPressed && !inAir)
            {
                speedX -= speed;
            }
            else if (w.LeftPressed && speedX >= -5)
            {
                speedX -= speed / 2;
            }

            if (w.RightPressed && !inAir)
            {
                speedX += speed;
            }
            else if (w.RightPressed && speedX <= 5)
            {
                speedX += speed / 2;
            }

            //left and right inertia 
            if (!inAir)
                speedX *= GroundFriction;


            x += (int)speedX;



            //jump press
            if (!inAir && w.SpacePressed && !bhopForcer) {
                speedY += jumpHeight;
                inAir = true;
                bhopForcer = true;

                //horizontal speedboost
                if (w.LeftPressed)
                {
                    speedX -= speedBoost;
                }
                if (w.RightPressed)
                {
                    speedX += speedBoost;
                }
            }

            // slowing down jump rising
            if (!falling)
                speedY *= gravity;


            //falling
            if (speedY < 1f && speedY != 0 && !falling)
            {
                speedY = -2;
                falling = true;
            }
            else if (speedY < 0f && falling)
            {
                speedY *= fallingIncrease;
            }

            //hiting the ground
            if (y + (int)speedY < 0)
            {
                y = 0;
                speedY = 0;
                inAir = false;
                falling = false;
            }

            if (bhopForcer && !inAir && !w.SpacePressed)
            {
                bhopForcer = false;
            }
       
            y += (int)speedY;
        }
    }
}
