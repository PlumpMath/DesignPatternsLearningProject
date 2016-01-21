using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Observer
{
    class ButtonObserver : Button, IObserver
    {
        public void Update (object sub)
        {
            ObserverState newState = (ObserverState)sub;

            if (newState == ObserverState.Observing)
            {
                Enabled = true;
            }
            else
            {
                Enabled = false;
            }
        }
    }
}
