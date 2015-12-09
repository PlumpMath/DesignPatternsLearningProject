using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Observer
{
    class ConcreteSubject : Subject
    {
        private int m_timeAsSecond = DateTime.Now.Second;
        private object m_lock = new object();

        private Timer m_timer = null;
        public override void Notify()
        {
            foreach (IObserver item in m_objectList)
            {
                item.Update(this);
            }
        }

        public int TimeAsSecond
        {
            get
            {
                lock (m_lock)
                {
                    return m_timeAsSecond;
                }
            }
        }

        public void StartUpdateByMyself()
        {
            m_timer = new Timer(TryToUpdateTimeAsSecond, null, 0, 200);
        }

        public void StopUpdateByMyself()
        {
            m_timer.Dispose();
            m_timer = null;
        }

        private void TryToUpdateTimeAsSecond(object o)
        {
            int newTimeAsSecond = DateTime.Now.Second;
            bool toUpdate = false;

            lock (m_lock)
            {
                if (newTimeAsSecond != m_timeAsSecond)
                {
                    m_timeAsSecond = newTimeAsSecond;
                    toUpdate = true;
                }
            }

            if (toUpdate)
            {
                base.Notify();
            }
        }
    }
}
