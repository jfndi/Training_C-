#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

const unsigned modulo = (1U << 31);
const unsigned array_size = modulo >> 3;

class BitArray
{
private:
    unsigned int size_ = 0;
    unsigned char* buffer_ = nullptr;

    unsigned char* get_byte(unsigned int position)
    {
        return &buffer_[position / 8];
    }

public:
    BitArray() = delete;
    BitArray(BitArray& array) = delete;
    BitArray(BitArray&& array) = delete;

    BitArray& operator=(const BitArray& array) const = delete;
    BitArray& operator=(const BitArray&& array) const = delete;

    BitArray(unsigned int N) : size_{ N }
    {
        buffer_ = new unsigned char[size_];

        memset(buffer_, 0, size_);
    }

    ~BitArray()
    {
        delete[] buffer_;
    }

    void set_bit(unsigned int position)
    {
        unsigned char* byte;
        byte = get_byte(position);

        *byte |= (1U << (position % 8));
    }

    bool test_bit(unsigned int position)
    {
        unsigned char* byte;

        byte = get_byte(position);
        return ((*byte) & (1U << (position % 8)));
    }
};

constexpr unsigned int MAX_ARRAY_SIZE = ((1U << 31) >> 3);

int main()
{
    unsigned int count;
    unsigned int n, s, p, q;
    BitArray bit_array(MAX_ARRAY_SIZE);

    n = s = p = q = 0;
    cin >> n >> s >> p >> q;

    unsigned previous = s % modulo;
    bit_array.set_bit(previous);
    count = 1;
    for (unsigned i = 1; i <= n - 1; i++)
    {
        unsigned int res = ((previous * p) + q) % modulo;
        previous = res;
        if (!bit_array.test_bit(previous))
        {
            bit_array.set_bit(previous);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}