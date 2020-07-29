
#pragma once

#include <vector>
#include <array>

namespace eliastocco { // you can change namespace    
       
    namespace container {
    
        namespace dynamic {
        
            typedef /*long unsigned*/ int t_dim;
            typedef /*long*/ long unsigned int ut_dim;
        
            constexpr ut_dim decrease ( ut_dim a ) { return (a > 1 ) ? ( a - 1 ) : 0 ; }
            
            template < class type , template <class...> class STL_container >
                class my_dynamic_vector ;
                
            template < ut_dim Dimension , class type , 
                template <class...> class STL_container > 
                    class dynamic_vector ;
        
        
        }
        
    }
    
}

#include "header/my_dynamic_vector.h"
#include "header/dynamic_vector.h"
#include "header/dynamic_vector_specialization.h"
