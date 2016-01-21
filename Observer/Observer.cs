using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    interface IObserver
    {
       void Update(object sub);
    }
}
