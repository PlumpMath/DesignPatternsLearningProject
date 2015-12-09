using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    class Subject
    {
        protected List<Observer> m_objectList = new List<Observer>();

        public virtual int TimeAsSecond { get; }

        public void Attach(Observer obj)
        {
            m_objectList.Add(obj);
        }

        public void Detach(Observer obj)
        {
            m_objectList.Remove(obj);
        }

        public void DetachAll()
        {
            m_objectList.Clear();
        }

        public void Notify()
        {
            foreach (Observer item in m_objectList)
            {
                item.Update(this);
            }
        }
    }
}
