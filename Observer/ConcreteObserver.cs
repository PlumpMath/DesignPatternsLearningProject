using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    class ConcreteObserver : IObserver
    {
        private string m_name;

        public ConcreteObserver(string name)
        {
            m_name = name;
        }

        public void Update(object sub)
        {
            Trace.WriteLine(Name + " see " + ((TimeAsSecondSubject)sub).TimeAsSecond.ToString());
        }

        public string Name
        {
            get
            {
                return m_name;
            }
        }
    }
}
