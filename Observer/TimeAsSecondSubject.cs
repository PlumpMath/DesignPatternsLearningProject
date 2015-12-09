using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Observer
{
    class TimeAsSecondSubject : Subject
    {
        private DateTime m_currentTime = DateTime.Now;
        private object m_lock = new object();

        private Timer m_timer = null;

        public string CurrentTime
        {
            get
            {
                lock (m_lock)
                {
                    return m_currentTime.Year + "-" + m_currentTime.Month + "-" + m_currentTime.Day + " "
                        + m_currentTime.Hour + ":" + m_currentTime.Minute + ":" + m_currentTime.Second;
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
            DateTime newTime = DateTime.Now;
            bool toUpdate = false;

            lock (m_lock)
            {
                if (    newTime.Second != m_currentTime.Second
                    ||  newTime.Minute != m_currentTime.Minute
                    ||  newTime.Hour != m_currentTime.Hour
                    ||  newTime.Day != m_currentTime.Day
                    ||  newTime.Month != m_currentTime.Month
                    ||  newTime.Year != m_currentTime.Year)
                {
                    m_currentTime = newTime;
                    toUpdate = true;
                }
            }

            if (toUpdate)
            {
                Notify();
            }
        }
    }
}
