using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    class Subject : BaseSubject
    {
        public virtual int TimeAsSecond { get; }
        public override void Notify()
        {
            foreach (IObserver item in m_objectList)
            {
                item.Update(this);
            }
        }
    }
}
