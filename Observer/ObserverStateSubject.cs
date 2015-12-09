using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    enum ObserverState
    {
        Standby,
        Observing,
    }

    class ObserverStateSubject : Subject
    {
        private ObserverState m_state = ObserverState.Standby;

        public ObserverState State
        {
            get { return m_state; }
            set { m_state = value; }
        }

        public override void Notify()
        {
            foreach (IObserver item in m_objectList)
            {
                item.Update(this.State);
            }
        }
    }

}
