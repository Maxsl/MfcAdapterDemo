#define DEBUG  //Workaround - This allows Debug.Write to work.

//This is a list of commonly used namespaces for an application class.
using System.Windows;

namespace WpfPageDemo
{
    /// <summary>
    /// Interaction logic for Application.xaml
    /// </summary>

    public partial class MyApp : Application
    {
        /// <summary>
        /// Constructor
        /// </summary>
        public MyApp() 
        {
            this.DispatcherUnhandledException += new System.Windows.Threading.DispatcherUnhandledExceptionEventHandler(MyApp_DispatcherUnhandledException);
        }

        void MyApp_DispatcherUnhandledException(object sender, System.Windows.Threading.DispatcherUnhandledExceptionEventArgs e)
        {
            if (e.Exception is System.IO.FileNotFoundException || e.Exception is System.FormatException)
            {
                MessageBoxButton buttons = MessageBoxButton.YesNo;

                MessageBoxResult res = System.Windows.MessageBox.Show("Not critical error: " + e.Exception.Message + ". Do you want continue?", "", buttons);

                if (res == MessageBoxResult.Yes)
                    // Prevent default unhandled exception processing
                    e.Handled = true;
            }
            else
            {
                System.Windows.MessageBox.Show("Critical error: " + e.Exception.Message + ". Application would be terminated.");
            }
        }
    }
}