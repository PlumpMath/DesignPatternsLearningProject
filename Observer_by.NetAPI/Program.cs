using System;
using System.Collections.Generic;
using System.Text;

namespace Observer_by.NetAPI
{
    class Program
    {
        static void Main(string[] args)
        {
            NewVersionPublishHandler newVerPublisher = new NewVersionPublishHandler();

            PublishMonitor monitorBoard = new PublishMonitor("Publish Board");
            monitorBoard.Subscribe(newVerPublisher);

            Console.WriteLine("\nGenernate new version:");
            newVerPublisher.NewVersionGenernate(
                ReadStringFromConsole("VersionNumber"), ReadStringFromConsole("Description"));

            PublishMonitor monitorTechSupport = new PublishMonitor("Tech Support");
            monitorTechSupport.Subscribe(newVerPublisher);

            Console.WriteLine("\nGenernate new version:");
            newVerPublisher.NewVersionGenernate(
                ReadStringFromConsole("VersionNumber"), ReadStringFromConsole("Description"));

            monitorBoard.Unsubscribe();

            Console.WriteLine("\nGenernate new version:");
            newVerPublisher.NewVersionGenernate(
                ReadStringFromConsole("VersionNumber"), ReadStringFromConsole("Description"));


            Console.ReadKey();
        }

        static string ReadStringFromConsole(string itemName)
        {
            Console.Write(itemName + ":");
            string itemValue = Console.ReadLine();

            return itemValue;
        }
    }
}
