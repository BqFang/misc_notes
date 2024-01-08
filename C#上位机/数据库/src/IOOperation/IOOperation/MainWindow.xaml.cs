using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace IOOperation
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //// 1.创建文件流
            //FileStream fs = new FileStream("E:\\上位机\\C#上位机\\数据库\\src\\myfile.txt", FileMode.Create);
            //// 2.创建写入器
            //StreamWriter sw = new StreamWriter(fs);
            //// 3.以流的方式进行写入
            //sw.Write(this)
        }

        
    }
}
