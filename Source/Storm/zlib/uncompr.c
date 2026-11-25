// Altered from the original zlib source.
#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_DATA_ERROR    (-3)
#define Z_BUF_ERROR     (-5)
#define Z_FINISH        4
#define ZLIB_VERSION    "1.2.8"

typedef struct z_stream_s
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned long total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char* msg;
    struct internal_state* state;
    void* (__fastcall* zalloc)(void* opaque, unsigned int items, unsigned int size);
    void (__fastcall* zfree)(void* opaque, void* address);
    void* opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

int __fastcall inflateInit_(z_stream* strm, const char* version, int stream_size); // 0x00429A10
int __fastcall inflate(z_stream* strm, int flush); // 0x00429BB0
int __fastcall inflateEnd(z_stream* strm); // 0x0042B170

#define inflateInit(strm) inflateInit_((strm), ZLIB_VERSION, (int)sizeof(z_stream))

// 0x006C79C0
int __fastcall uncompress(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen)
{
    z_stream stream;
    int err;

    stream.next_in = (unsigned char*)source;
    stream.avail_in = (unsigned int)sourceLen;
    /* Check for source > 64K on 16-bit machine: */
    if ((unsigned long)stream.avail_in != sourceLen) return Z_BUF_ERROR;

    stream.next_out = dest;
    stream.avail_out = (unsigned int)*destLen;
    if ((unsigned long)stream.avail_out != *destLen) return Z_BUF_ERROR;

    stream.zalloc = 0;
    stream.zfree = 0;

    err = inflateInit(&stream);
    if (err != Z_OK) return err;

    err = inflate(&stream, Z_FINISH);
    if (err != Z_STREAM_END) {
        inflateEnd(&stream);
        if (err == Z_NEED_DICT || (err == Z_BUF_ERROR && stream.avail_in == 0))
            return Z_DATA_ERROR;
        return err;
    }
    *destLen = stream.total_out;

    err = inflateEnd(&stream);
    return err;
}
