using System;
using System.Collections.Generic;
using System.Text;

namespace Observer_by.NetAPI
{
    class NewVersionPublishHandler : IObservable<NewSoftwareVersionInfo>
    {
        private List<IObserver<NewSoftwareVersionInfo>> m_observers = new List<IObserver<NewSoftwareVersionInfo>>();

        public IDisposable Subscribe(IObserver<NewSoftwareVersionInfo> observer)
        {

            // Check whether observer is already registered. If not, add it 
            if (!m_observers.Contains(observer))
            {
                m_observers.Add(observer);

                //TODO: Provide observer with existing data if need.
                
            }
            return new Unsubscriber<NewSoftwareVersionInfo>(m_observers, observer);
        }

        public void NewVersionGenernate(string versionNumber, string description)
        {
            NewSoftwareVersionInfo newVer = new NewSoftwareVersionInfo(versionNumber, description);

            //Notify observers
            foreach (IObserver<NewSoftwareVersionInfo> item in m_observers)
            {
                item.OnNext(newVer);
            }
        }

        public void PublishDoneNotify()
        {
            //Notify observers
            foreach (IObserver<NewSoftwareVersionInfo> item in m_observers)
            {
                item.OnCompleted();
            }
            m_observers.Clear();
        }
    }
}
