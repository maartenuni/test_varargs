

typedef struct _one {
    int a;
    const char* msg;
} one_t;

/* this struct "derives" from struct _one */
typedef struct _two {
    one_t	parent;
    double	pi;
    double  e;
}two_t;

enum status_t {
    STATUS_SUCCES,
    STATUS_INVALID_ARGUMENT,
    STATUS_ERROR
};

enum init_one_flags {
    INIT_ONE_A,			// 2nd argument should be of type int
    INIT_ONE_MSG,		// 3rd argument should be const char*
    INIT_ONE_FINISHED,	// takes no arugment, but rather tell init1 should be finished.
    INIT_ONE_SENTINAL	// Keep at the last position.
};

enum init_two_flags {
    INIT_TWO_PI = INIT_ONE_SENTINAL,	// 2nd arugument should be of type double.
    INIT_TWO_E,                         // 2nd argument shoudl be double.
    INIT_TWO_FINISHED,					// takes no arugment, but rather tell init2 should be finished.
    INIT_TWO_SENTINAL,					// for init3...
};

#ifdef __cplusplus
extern "C" {
#endif

int init_two(two_t* two, ...);

//void init_one(one_t* one, ...);

#ifdef __cplusplus
}
#endif
