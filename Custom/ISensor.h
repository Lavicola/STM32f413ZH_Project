#include <stdint.h>
class ISensor
{
    public:
        	virtual void Start(void) = 0;
					virtual uint8_t Check_Response (void) = 0;
					virtual uint8_t Read (void)= 0;
					virtual ~ISensor(){};
};
