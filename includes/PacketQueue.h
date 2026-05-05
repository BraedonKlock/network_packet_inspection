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

    		T pop()
    		{
        		std::unique_lock<std::mutex> lock(mutex);

        		cv.wait(lock, [this] {
            			return !queue.empty();
        		});

        		T packet = queue.front();
        		queue.pop();

        		return packet;
    		}
};

#endif
