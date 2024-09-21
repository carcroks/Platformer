using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace Platformer
{
    //<>

    internal class Grid
    {

        List<List<Object>> Matrix;
        MainWindow w;
        int unit;

        public Grid(MainWindow w)
        {
            this.w = w;

            Matrix = new List<List<Object>>();

            unit = 10;
        }

        public void GenerateGrid()
        {
            for (int i = 0; i < w.field.Height / unit; i++)
            {
                Matrix.Add(new List<Object>());
                for (int j = 0; j < w.field.Width / unit; j++)
                {
                    Matrix[i].Add(null);
                }
            }
        }

        public void showGrid()
        {
            for (int i = 0; i < Matrix.Count; i++)
            {
                for (int j = 0; j < Matrix.Count; j++)
                {
                    Matrix[i][j].showImage();
                }
            }
    }
}
