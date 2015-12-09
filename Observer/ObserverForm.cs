using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Observer
{
    public partial class ObserverForm : Form
    {
        private ConcreteObserver m_concreteObserver = null;
        private ConcreteSubject m_concreteSubject = null;

        public ObserverForm()
        {
            InitializeComponent();
        }

        private void buttonDoObserve_Click(object sender, EventArgs e)
        {
            if (buttonDoObserve.Text.Contains("Do Observe"))
            {
                m_concreteSubject = new ConcreteSubject();
                m_concreteObserver = new ConcreteObserver();

                m_concreteSubject.Attach(m_concreteObserver);
                m_concreteSubject.StartUpdateByMyself();

                buttonDoObserve.Text = "Stop Observe";
            }
            else
            {
                m_concreteSubject.DetachAll();
                m_concreteSubject.StopUpdateByMyself();
                m_concreteSubject = null;
                m_concreteObserver = null;

                buttonDoObserve.Text = "Do Observe";
            }

        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }

        private void watch1_button_Click(object sender, EventArgs e)
        {
            if (watch1_button.Text.Contains("Watch"))
            {


                watch1_button.Text = "Stop Watch";
            }
            else
            {

                watch1_button.Text = "Watch";
            }
        }
    }
}
