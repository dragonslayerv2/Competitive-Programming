#include<iostream>
#include<map>
using namespace std;


class clock
{
	private:
		map<int,bool> empty_slots;
	public:
		clock()
		{
			initialise();
		}
		void initialise()
		{
			empty_slots.clear();
		}
		clock(int llimit,int ulimit,int gap)
		{
			initialise(llimit,ulimit,gap);
		}
		
		void initialise(int llimit,int ulimit,int gap)
		{
			for(int i=llimit;i<=ulimit;i+=gap)
				empty_slots[i]=true;
		}
		
		bool is_occupied(int time)
		{
			return empty_slots.find(time)==empty_slots.end();
		}
		
		bool occupy(int time)
		{
			map<int,bool>::iterator loc=empty_slots.find(time);
			if(loc==empty_slots.end())
				return false;
			else
			{
				empty_slots.erase(loc);
				return true;	
			}
		}
		
		class no_slots{};
		
		int find_empty(int time)
		{
			if(empty_slots.find(time)==empty_slots.end())
			{
				map<int,bool>::iterator loc=empty_slots.insert(make_pair(time,false)).first;
				map<int,bool>::iterator freeloc=loc;
				freeloc--;
				empty_slots.erase(loc);
				if(freeloc!=empty_slots.end())
					return freeloc->first;	
				else
					throw no_slots();
				empty_slots.erase(time);			
			}
			else
				return time;
		}
		
		size_t slots_count()
		{
			return empty_slots.size();
		}
		
		class out_of_range{};
		
		void free(int time)
		{
			empty_slots[time]=true;
		}
		
		
};
int main()
{
}
