
#pragma once

namespace eliastocco {       
    namespace container {    
        namespace dynamic {
            
            template < class type , template <class...> class STL_container >
                class my_dynamic_vector : public STL_container < type > {
                    public :
                        my_dynamic_vector ( std :: array < t_dim , 1 > Lenght = { 0 } ) 
                            : STL_container < type > ( Lenght [ 0 ] ) {};
                };
            
        }        
    }
}
