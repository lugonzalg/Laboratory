#include <cinttypes>
#include <cstring>

class SeatManager {
public:

    uint8_t *seats;
	std::size_t  size;
	std::size_t  free_pos;

    SeatManager(int n) {
        seats = new uint8_t[n];
        this->size = n;
        this->free_pos = 0;
        memset(seats, 0, n);
    }

    int reserve() {
        int tmp;

        tmp = this->free_pos + 1;
        this->seats[this->free_pos] = 1;
        while (this->free_pos < this->size and this->seats[this->free_pos])
			this->free_pos++;
        return tmp;
    }

    void unreserve(int seatNumber) {
        if (seatNumber > this->size)
            return ;

        this->seats[seatNumber - 1] = 0;
        if (seatNumber - 1 < this->free_pos)
            this->free_pos = seatNumber - 1;
    }
};

int main() {
	SeatManager	sm(5);

	sm.reserve();
	sm.reserve();
	sm.unreserve(2);
	sm.reserve();
	sm.reserve();
	sm.reserve();
	sm.reserve();
	sm.unreserve(5);

	return 0;
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
