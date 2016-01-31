using System;
using System.Collections.Generic;

namespace Observer_by.NetAPI
{
    internal class Unsubscriber<NewSoftwareVersionInfo> : IDisposable
    {
        private List<IObserver<NewSoftwareVersionInfo>> m_observers;
        private IObserver<NewSoftwareVersionInfo> observer;

        internal Unsubscriber(List<IObserver<NewSoftwareVersionInfo>> m_observers, IObserver<NewSoftwareVersionInfo> observer)
        {
            this.m_observers = m_observers;
            this.observer = observer;
        }

        public void Dispose()
        {
            if (observer != null && m_observers.Contains(observer))
            {
                m_observers.Remove(observer);
            }
        }
    }
}