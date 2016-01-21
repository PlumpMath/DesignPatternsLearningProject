using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Observer
{
    public partial class ObserverForm : Form, IObserver
    {
        private ConcreteObserver m_concreteObserver = null;
        private CurrentTimeSubject m_concreteSubject = null;
        private ObserverStateSubject m_observerState = new ObserverStateSubject();

        public ObserverForm()
        {
            InitializeComponent();

            m_observerState.Attach(this);
            m_observerState.Attach(labelObserveState);
            m_observerState.Attach(watch1_button);
        }

        public void Update(object sub)
        {
            ObserverState newState = (ObserverState)sub;

            if (newState == ObserverState.Standby)
            {
                m_concreteSubject.DetachAll();
                m_concreteSubject.StopUpdateByMyself();
                m_concreteSubject = null;
                m_concreteObserver = null;

                //watch1_button.Enabled = false;
                buttonDoObserve.Text = "Do Observe";

            }
            else
            {
                m_concreteSubject = new CurrentTimeSubject();
                m_concreteObserver = new ConcreteObserver("Observe On Trace");

                m_concreteSubject.Attach(m_concreteObserver);
                m_concreteSubject.StartUpdateByMyself();

                //watch1_button.Enabled = true;
                buttonDoObserve.Text = "Stop Observe";

            }
        }

        private void buttonDoObserve_Click(object sender, EventArgs e)
        {
            if (buttonDoObserve.Text.Contains("Do Observe"))
            {
                //m_concreteSubject = new TimeAsSecondSubject();
                //m_concreteObserver = new ConcreteObserver("Observe On Trace");

                //m_concreteSubject.Attach(m_concreteObserver);
                //m_concreteSubject.StartUpdateByMyself();

                //watch1_button.Enabled = true;
                //buttonDoObserve.Text = "Stop Observe";

                m_observerState.State = ObserverState.Observing;
            }
            else
            {
                //m_concreteSubject.DetachAll();
                //m_concreteSubject.StopUpdateByMyself();
                //m_concreteSubject = null;
                //m_concreteObserver = null;

                //watch1_button.Enabled = false;
                //buttonDoObserve.Text = "Do Observe";

                m_observerState.State = ObserverState.Standby;
            }
            m_observerState.Notify();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }

        private void watch1_button_Click(object sender, EventArgs e)
        {
            if (watch1_button.Text.Contains("Do Watch"))
            {
                m_concreteSubject.Attach(textBoxTimeAsSecond);

                watch1_button.Text = "Stop Watch";
            }
            else
            {
                m_concreteSubject.Detach(textBoxTimeAsSecond);

                watch1_button.Text = "Do Watch";
            }
        }
    }
}
