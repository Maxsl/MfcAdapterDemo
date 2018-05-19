using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Input;
using AS.MfcHost;

namespace WpfDemo
{
    internal class CommonCommands
    {
        public static void InitializeCommands()
        {
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(ApplicationCommands.Cut, executedCut, canExecuteCut));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(ApplicationCommands.Copy, executedCopy, canExecuteCopy));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(ApplicationCommands.Paste, executedPaste, canExecutePaste));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(ApplicationCommands.Print, executedPrint, canExecutePrint));
        }

        static void executedCut(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_CUT);
                else
                    view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_CUT);
            }
        }
        static void canExecuteCut(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_CUT, e);
                else
                    view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_CUT, e);
            }
        }
        static void executedCopy(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_COPY);
                else
                    view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_COPY);
            }
        }
        static void canExecuteCopy(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_COPY, e);
                else
                    view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_COPY, e);
            }
        }
        static void executedPaste(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_PASTE);
                else
                    view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_PASTE);
            }
        }
        static void canExecutePaste(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.EDIT_PASTE, e);
                else
                    view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.EDIT_PASTE, e);
            }
        }
        static void executedPrint(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.FILE_PRINT);
                else
                    view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.FILE_PRINT);
            }
        }
        static void canExecutePrint(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null)
            {
                if (view.MfcRootNamespace == "AS.UmlEditor")
                    view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.FILE_PRINT, e);
                else
                    view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.FILE_PRINT, e);
            }
        }
    }

    public class UmlEditorCommands
    {
        private static RoutedCommand _class;
        private static RoutedCommand _template;
        private static RoutedCommand _package;
        private static RoutedCommand _interface;
        private static RoutedCommand _note;
        private static RoutedCommand _label;
        private static RoutedCommand _link;
        private static RoutedCommand _displset;

        public static RoutedCommand Class { get { return _class; } }
        public static RoutedCommand Template { get { return _template; } }
        public static RoutedCommand Package { get { return _package; } }
        public static RoutedCommand Interface { get { return _interface; } }
        public static RoutedCommand Note { get { return _note; } }
        public static RoutedCommand Label { get { return _label; } }
        public static RoutedCommand Link { get { return _link; } }
        public static RoutedCommand DisplSet { get { return _displset; } }

        public static void InitializeCommands()
        {
            _class = new RoutedCommand("Class", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_class, executedClass, canExecuteClass));
            _template = new RoutedCommand("Template", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_template, executedTemplate, canExecuteTemplate));
            _package = new RoutedCommand("Package", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_package, executedPackage, canExecutePackage));
            _interface = new RoutedCommand("Interface", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_interface, executedInterface, canExecuteInterface));
            _note = new RoutedCommand("Note", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_note, executedNote, canExecuteNote));
            _label = new RoutedCommand("Label", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_label, executedLabel, canExecuteLabel));
            _link = new RoutedCommand("Link", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_link, executedLink, canExecuteLink));
            _displset = new RoutedCommand("DisplSet", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_displset, executedDisplSet, canExecuteDisplSet));
        }
        static void executedClass(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_CLASS);
            }
        }
        static void canExecuteClass(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_CLASS, e);
            }
        }
        static void executedTemplate(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_TEMPLATE);
            }
        }
        static void canExecuteTemplate(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_TEMPLATE, e);
            }
        }
        static void executedPackage(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_PACKAGE);
            }
        }
        static void canExecutePackage(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_PACKAGE, e);
            }
        }
        static void executedInterface(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_INTERFACE);
            }
        }
        static void canExecuteInterface(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_INTERFACE, e);
            }
        }
        static void executedNote(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_NOTE);
            }
        }
        static void canExecuteNote(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_NOTE, e);
            }
        }
        static void executedLabel(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LABEL);
            }
        }
        static void canExecuteLabel(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LABEL, e);
            }
        }
        static void executedLink(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LINK);
            }
        }
        static void canExecuteLink(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_LINK, e);
            }
        }
        static void executedDisplSet(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_DISPLAY_PROPERTIES);
            }
        }
        static void canExecuteDisplSet(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.UmlEditor")
            {
                view.OnUpdateCmdMsg((int)AS.UmlEditor.MfcCommand.BUTTON_DISPLAY_PROPERTIES, e);
            }
        }
    }

    public class DlgEditorCommands
    {
        private static RoutedCommand _button;
        private static RoutedCommand _checkBox;
        private static RoutedCommand _combobox;
        private static RoutedCommand _edit;
        private static RoutedCommand _groupbox;
        private static RoutedCommand _listbox;
        private static RoutedCommand _none;
        private static RoutedCommand _radiobutton;
        private static RoutedCommand _static;
        private static RoutedCommand _multidraw;
        private static RoutedCommand _margins;
        private static RoutedCommand _restrain;
        private static RoutedCommand _settings;
        private static RoutedCommand _showgrid;
        private static RoutedCommand _snaptogrid;
        private static RoutedCommand _zoomin;
        private static RoutedCommand _zoomout;

        public static RoutedCommand Button { get { return _button; } }
        public static RoutedCommand CheckBox { get { return _checkBox; } }
        public static RoutedCommand Combobox { get { return _combobox; } }
        public static RoutedCommand Edit { get { return _edit; } }
        public static RoutedCommand Groupbox { get { return _groupbox; } }
        public static RoutedCommand Listbox { get { return _listbox; } }
        public static RoutedCommand None { get { return _none; } }
        public static RoutedCommand Radiobutton { get { return _radiobutton; } }
        public static RoutedCommand Static { get { return _static; } }
        public static RoutedCommand Multidraw { get { return _multidraw; } }
        public static RoutedCommand Margins { get { return _margins; } }
        public static RoutedCommand Restrain { get { return _restrain; } }
        public static RoutedCommand Settings { get { return _settings; } }
        public static RoutedCommand Showgrid { get { return _showgrid; } }
        public static RoutedCommand Snaptogrid { get { return _snaptogrid; } }
        public static RoutedCommand Zoomin { get { return _zoomin; } }
        public static RoutedCommand Zoomout { get { return _zoomout; } }

        public static void InitializeCommands()
        {
            _button = new RoutedCommand("Button", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_button, executedButton, canExecuteButton));
            _checkBox = new RoutedCommand("CheckBox", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_checkBox, executedCheckBox, canExecuteCheckBox));
            _combobox = new RoutedCommand("Combobox", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_combobox, executedCombobox, canExecuteCombobox));
            _edit = new RoutedCommand("Edit", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_edit, executedEdit, canExecuteEdit));
            _groupbox = new RoutedCommand("Groupbox", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_groupbox, executedGroupbox, canExecuteGroupbox));
            _listbox = new RoutedCommand("Listbox", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_listbox, executedListbox, canExecuteListbox));
            _none = new RoutedCommand("None", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_none, executedNone, canExecuteNone));
            _radiobutton = new RoutedCommand("Radiobutton", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_radiobutton, executedRadiobutton, canExecuteRadiobutton));
            _static = new RoutedCommand("Static", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_static, executedStatic, canExecuteStatic));
            _multidraw = new RoutedCommand("Multidraw", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_multidraw, executedMultidraw, canExecuteMultidraw));
            _margins = new RoutedCommand("Margins", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_margins, executedMargins, canExecuteMargins));
            _restrain = new RoutedCommand("Restrain", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_restrain, executedRestrain, canExecuteRestrain));
            _settings = new RoutedCommand("Settings", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_settings, executedSettings, canExecuteSettings));
            _showgrid = new RoutedCommand("Showgrid", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_showgrid, executedShowgrid, canExecuteShowgrid));
            _snaptogrid = new RoutedCommand("Snaptogrid", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_snaptogrid, executedSnaptogrid, canExecuteSnaptogrid));
            _zoomin = new RoutedCommand("Zoomin", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_zoomin, executedZoomin, canExecuteZoomin));
            _zoomout = new RoutedCommand("Zoomout", typeof(ViewFrameworkElement));
            CommandManager.RegisterClassCommandBinding(typeof(ViewFrameworkElement), new CommandBinding(_zoomout, executedZoomout, canExecuteZoomout));
        }
        static void executedButton(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_BUTTON);
            }
        }
        static void canExecuteButton(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_BUTTON, e);
            }
        }
        static void executedCheckBox(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_CHECKBOX);
            }
        }
        static void canExecuteCheckBox(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_CHECKBOX, e);
            }
        }
        static void executedCombobox(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_COMBOBOX);
            }
        }
        static void canExecuteCombobox(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_COMBOBOX, e);
            }
        }
        static void executedEdit(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_EDIT);
            }
        }
        static void canExecuteEdit(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_EDIT, e);
            }
        }
        static void executedGroupbox(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_GROUPBOX);
            }
        }
        static void canExecuteGroupbox(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_GROUPBOX, e);
            }
        }
        static void canExecuteListbox(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_LISTBOX, e);
            }
        }
        static void executedListbox(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_LISTBOX);
            }
        }
        static void canExecuteNone(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_NONE, e);
            }
        }
        static void executedNone(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_NONE);
            }
        }
        static void canExecuteRadiobutton(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_RADIOBUTTON, e);
            }
        }
        static void executedRadiobutton(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_RADIOBUTTON);
            }
        }
        static void canExecuteStatic(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_STATIC, e);
            }
        }
        static void executedStatic(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ADD_STATIC);
            }
        }
        static void canExecuteMultidraw(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.BUTTON_MULTIDRAW, e);
            }
        }
        static void executedMultidraw(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.BUTTON_MULTIDRAW);
            }
        }
        static void canExecuteMargins(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.MARGINS, e);
            }
        }
        static void executedMargins(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.MARGINS);
            }
        }
        static void canExecuteRestrain(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.RESTRAIN, e);
            }
        }
        static void executedRestrain(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.RESTRAIN);
            }
        }
        static void canExecuteSettings(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.SETTINGS, e);
            }
        }
        static void executedSettings(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.SETTINGS);
            }
        }
        static void canExecuteShowgrid(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.SHOW_GRID, e);
            }
        }
        static void executedShowgrid(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.SHOW_GRID);
            }
        }
        static void canExecuteSnaptogrid(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.SNAP_TO_GRID, e);
            }
        }
        static void executedSnaptogrid(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.SNAP_TO_GRID);
            }
        }
        static void canExecuteZoomin(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_IN_, e);
            }
        }
        static void executedZoomin(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_IN_);
            }
        }
        static void canExecuteZoomout(object sender, CanExecuteRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnUpdateCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_OUT_, e);
            }
        }
        static void executedZoomout(object sender, ExecutedRoutedEventArgs e)
        {
            ViewFrameworkElement view = sender as ViewFrameworkElement;
            if (view != null && view.MfcRootNamespace == "AS.DlgEditor")
            {
                view.OnCmdMsg((int)AS.DlgEditor.MfcCommand.ZOOM_OUT_);
            }
        }
    }


    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            CommonCommands.InitializeCommands();
            UmlEditorCommands.InitializeCommands();
            DlgEditorCommands.InitializeCommands();
        }
    }
}

