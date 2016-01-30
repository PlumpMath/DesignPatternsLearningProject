using System;
using System.Collections.Generic;
using System.Text;

namespace Observer_by.NetAPI
{
    class NewSoftwareVersionInfo
    {
        private string versionNumber;
        private string description;

        NewSoftwareVersionInfo(string versionNumber, string description)
        {
            this.versionNumber = versionNumber;
            this.description = description;
        }

        public string VersionNumber
        {
            get { return versionNumber; }
            set { versionNumber = value; }
        }

        public string Description
        {
            get { return description; }
            set { description = value; }
        }
    }
}
