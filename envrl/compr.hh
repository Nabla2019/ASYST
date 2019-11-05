*comdeck compr
#define BITS          12          /* bits for a code */
#define HASHING_SHIFT BITS-8
#define MAX_VALUE     (1 << BITS) -1
#define MAX_CODE      MAX_VALUE - 1
#define BITS_WORD     32          /* bits in a word */
#define DICT_HITS     -20         /* Limit for dictionary misses */
#define FLUSH_CODE    256         /* If FLUSH_CODE, a new dictionary  */
#define BREAK_CODE    257         /* If BREAK_CODE, seperate compress */
#define FIRST_CODE    258         /* Start of compression codes */
#define TRUE          1
#define FALSE         0
#define TABLE_SIZE    5021
 
void *malloc();
 
FILE          *lzw_file;
int           *code_value;        /* Code value array      */
unsigned int  *prefix_code;       /* Prefix codes array    */
unsigned char *append_character;  /* Appended chars array  */
unsigned char *over_flow;         /* Over-flow chars on expan*/
unsigned char decode_stack[4000]; /* Decoded string array */
unsigned int  next_code;
unsigned int  string_code;
unsigned int  new_code;
unsigned int  old_code;
unsigned char *expn_str;
unsigned int  len_over;    /* numb of bytes not stored */
                           /* in str but unpacked */
unsigned int  index_over;  /* cur pointer to next posit */
                           /* in over flow */
int           comprs_on;   /* currently compressing */
int           expand_on;   /* currently expanding */
int           end_of_file;
int           bit_count;   /* loc in bit_buffer to store code*/
unsigned int bit_buffer;  /* buf to store code prior write */
int           last_code;   /* last code read and expanded */
int           dict_hits;   /* count on hits in dictionary */
