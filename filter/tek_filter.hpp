#ifndef AF39161A_4503_4CD6_A8CF_4B651C049F65
#define AF39161A_4503_4CD6_A8CF_4B651C049F65

#include "stdint.h"
#include "adt/tek_adt_fifo.hpp"

namespace tek
{
    namespace filter
    {

        class __FilterBase
        {
        protected:
            float val = 0;

        public:
            virtual void update(float dat) = 0;
            inline float get_result() { return val; }
        };

        class Lowpass : public __FilterBase
        {
        private:
            const float coeff;

        public:
            virtual void update(float dat);
            Lowpass(const float c);
        };

        template <uint8_t _cnt>
        // #define _cnt 8
        class Average : public __FilterBase
        {
        private:
            adt::FIFO<float, _cnt> fifo;

        public:
            Average(float initData = 0)
            {
                fifo.push(initData);
            }

            virtual void update(float nd)
            {
                this->val += nd;
                this->val -= fifo.top();
                fifo.push(nd);
            }

            inline float get_result() { return val / _cnt; }
        };

    }
}
#endif /* AF39161A_4503_4CD6_A8CF_4B651C049F65 */
