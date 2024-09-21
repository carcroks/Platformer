using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace Platformer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        DispatcherTimer GameTimer;

        public Boolean UpPressed = false, DownPressed = false, RightPressed = false, LeftPressed = false, SpacePressed = false;

        Character chara;

        public MainWindow()
        {
            InitializeComponent();
            field.Focus();

            GameTimer = new DispatcherTimer();
            GameTimer.Interval = TimeSpan.FromMilliseconds(16);
            GameTimer.Tick += GameTick;
            GameTimer.Start();

            chara = new Character(this);

        }

        public void GameTick(object sender, EventArgs e)
        {
            chara.Update();
            Canvas.SetBottom(character, chara.y);
            Canvas.SetLeft(character, chara.x);
            charx.Content = "x : " + chara.x;
            chary.Content = "y : " + chara.y;
            charxspeed.Content = "x speed: " + chara.speedX;
            charyspeed.Content = "y speed : " + chara.speedY;
        }

        public void KBD(object sender, KeyEventArgs e)
        {


            if (e.Key == Key.Q)
            {
                LeftPressed = true;
            }


            if (e.Key == Key.D)
            {
                RightPressed = true;
            }

            if (e.Key == Key.Space)
            {
                SpacePressed = true;
            }


        }

        public void KBU(object sender, KeyEventArgs e)
        {


            if (e.Key == Key.Q)
            {
                LeftPressed = false;
            }


            if (e.Key == Key.D)
            {
                RightPressed = false;
            }

            if (e.Key == Key.Space)
            {
                SpacePressed = false;
            }
        }
    }
}