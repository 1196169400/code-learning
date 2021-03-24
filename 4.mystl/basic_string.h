#include<new>

namespace mystl
{

template<typename CharType>
struct char_traits
{
    typedef CharType typechar;

    static size_t length(const typechar* str)
    {
        typechar* p = str;
        size_t num = 0;
        while(p++) {
            num++;
        }
    }

    static int compare(const typechar* str1, const typechar* str2)
    {
        typechar* p1 = str1, *p2 = str2;
        while (p1 != nullptr && p2 != nullptr) {
            if (*p1 > *p2)
                return 1;
            if (*p1 < *p2)
                return -1;
        }
        if (p1 != nullptr)
            return 1;
        if (p2 != nullptr)
            return -1;
        return 0;
    }

    static typechar* copy(typechar* src, typechar* dst, size_t n)
    {
        assert(src + n <= dst || dst + n <= src);
        typechar *r = dst;
        while (n--) {
            *dst++ = *src++;
        }
    }

    static typechar* move(typechar* src, typechar* dst,size_t n)
    {
        typechar* r = dst;
        if (src == dst)
            return ;
        if (src < dst && src + n > dst) {
            src += n-1;
            dst += n-1;
            while (n--)
                *dst-- = *src--;
        } else if {
            while (n--)
                *dst++ = *src++;
        }
        return r;
    }
    
    static typechar* fill(typechar* dst, typechar value, size_t count)
    {
        typechar* r = dst;
        while (count--) {
            *dst++ = value;
        }
        return r;
    }
}

template<typename CharType, typename CharTrait = char_traits<CharType>>
class basic_string
{
    typedef CharTrait                               trait_type;
    typedef CharTrait                               char_traits;

    typedef std::allocator<CharType>                allocator_type;
    typedef std::allocator<CharType>                data_allocator;

    typedef typename std::allocator<CharType>::value_type     value_type;

    typedef 
    //typedef std::allocator<CharType>::

public:
    static const size_t npos = static_cast<size_t>(-1);

private:
    iterator buffer_;

}




}