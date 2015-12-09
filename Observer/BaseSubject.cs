using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    class BaseSubject
    {
        protected List<IObserver> m_objectList = new List<IObserver>();

        public void Attach(IObserver obj)
        {
            m_objectList.Add(obj);
        }

        public void Detach(IObserver obj)
        {
            m_objectList.Remove(obj);
        }

        public void DetachAll()
        {
            m_objectList.Clear();
        }

        public virtual void Notify()
        {
        }

    }
}
