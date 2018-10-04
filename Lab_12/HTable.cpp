#include "HTable.h"
#include <iostream>

HTable::HTable() 
{
    dt = new data[23];
    max_size = 23;
    numel = 0;
    for(int counter = 0; counter < 23; counter++) {
        dt[counter].key = -1;
        dt[counter].value = "N/A";
    }
}

HTable::HTable(int t_size) 
{
    dt = new data[t_size];
    max_size = t_size;
    numel = 0;
    for(int counter = 0; counter < t_size; counter++) {
        dt[counter].key = -1;
        dt[counter].value = "N/A";
    }
}

int HTable::hash(int &k)
{
    return k % max_size;
}

int HTable::rehash(int &k) {
    return (k+1) % max_size;
}

int HTable::add(data &d)
{
    int index = hash(d.key);
    if(dt[index].key == -1) 
    {
        dt[index] = d;
        numel++;
        return 0;
    }
    else 
    {
        int counter = 0;
        while(dt[index].key != -1 && counter != max_size - 1) 
	{
            int key = d.key + counter;
            index = rehash(key);
            counter++;
        }
        if(dt[index].key == -1) 
        {
            dt[index] = d;
            numel++;
            return 0;
        }
    }
    return -1;
}

int HTable::remove(data &d)
{
    int index = hash(d.key);
    if(dt[index].key == d.key)
    {
        dt[index].key = -1;
        dt[index].value = "N/A";;
        numel--;
        return 0;
    } 
    else
    {
        int counter = 0;
        while(dt[index].key != d.key && counter != max_size - 1) 
	{
	    int key = d.key + counter;
            index = rehash(key);
            counter++;
        }
        if(dt[index].key == d.key) {
            dt[index].key = -1;
            dt[index].value = "N/A";
            numel--; 
            return 0;
        }
    }
    return -1;
}

void HTable::output()
{
    for(int counter = 0; counter < max_size; counter ++) {
        cout << counter <<  " ->\t" << dt[counter].key << "\t" << dt[counter].value << endl;
    }
    cout << "There are " << numel << " data elements in the hash table\n";
}
