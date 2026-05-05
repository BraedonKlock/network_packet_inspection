#ifndef PACKET_QUEUE_H
#define PACKET_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

template <typename T>
class PacketQueue
{
	private:
		std::queue<T> queue;
    		std::mutex mutex;
    		std::condition_variable cv;
		bool stopped = false;

	public:
    		void push(T packet)
    		{
        		{
            			std::lock_guard<std::mutex> lock(mutex);
            			queue.push(packet);
				std::cout << "packet pushed: " << std::endl;
        		}

        		cv.notify_one();
    		}
		
		bool pop(T& packet)
		{
    			std::unique_lock<std::mutex> lock(mutex);

    			cv.wait(lock, [this] {
        			return stopped || !queue.empty();
    			});

    			if (stopped && queue.empty())
    			{
        			return false;
    			}

    			packet = std::move(queue.front());
    			queue.pop();

    			return true;
		}

		void stop() 
		{
        		{
            			std::lock_guard<std::mutex> lock(mutex);
            			stopped = true;
        		}

        		cv.notify_all();
    		}
};

#endif
