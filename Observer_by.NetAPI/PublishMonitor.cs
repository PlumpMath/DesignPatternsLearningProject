using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Observer_by.NetAPI
{
    class PublishMonitor : IObserver<NewSoftwareVersionInfo>
    {
        private string m_name = null;
        private IDisposable m_cancellation = null;


        public PublishMonitor(string name)
        {
            m_name = name;
        }

        public void Subscribe(IObservable<NewSoftwareVersionInfo> provider)
        {
            m_cancellation = provider.Subscribe(this);
            Console.WriteLine("\n{0} Start Observe.", m_name);
        }

        public void Unsubscribe()
        {
            Console.WriteLine("\n{0} Stop Observe.", m_name);
            if (m_cancellation != null)
            {
                m_cancellation.Dispose();
            }
        }

        public void OnCompleted()
        {
            Console.WriteLine("<{0}> NewVersionPublish Done.", m_name);
        }

        public void OnError(Exception error)
        {
            throw new NotImplementedException();
        }

        public void OnNext(NewSoftwareVersionInfo value)
        {
            Console.WriteLine("\n<{0}> New Software Version here--->{1}:{2}.",
                m_name, value.VersionNumber, value.Description);
        }
    }
}
