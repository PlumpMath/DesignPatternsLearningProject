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
        public void Update(Subject sub)
        {
            Trace.WriteLine("I see " + sub.TimeAsSecond.ToString());
        }
    }
}
