using System;
using System.Collections.Generic;
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

using AS.MfcHost;
using AS.RowList;

namespace WpfPageDemo
{
    /// <summary>
    /// Interaction logic for Page2.xaml
    /// </summary>
    public partial class Page1 : Page
    {
        public Page1()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            FrameworkElement fe = sender as FrameworkElement;

            switch (fe.Name)
            {
                case "but1":
                    _RowListView.OnCmdMsg((int)AS.RowList.MfcCommand.VIEW_LICONS);
                    break;
                case "but2":
                    _RowListView.OnCmdMsg((int)AS.RowList.MfcCommand.VIEW_SICONS);
                    break;
                case "but3":
                    _RowListView.OnCmdMsg((int)AS.RowList.MfcCommand.VIEW_LISTMODE);
                    break;
                case "but4":
                    _RowListView.OnCmdMsg((int)AS.RowList.MfcCommand.VIEW_DETAILSMODE);
                    break;
                case "but5":
                    _RowListView.OnCmdMsg((int)AS.RowList.MfcCommand.VIEW_ROWDETAILS);
                    break;
            }
        }

    
    }
}
