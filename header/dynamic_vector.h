
#pragma once

#define thisclass dynamic_vector<Dimension,type,STL_container>                        
#define motherclass my_dynamic_vector<dynamic_vector<decrease(Dimension),\
type,STL_container>,STL_container>                        
#define childclass dynamic_vector<decrease(Dimension),type,STL_container>

namespace eliastocco {       
    namespace container {    
        namespace dynamic {
            
            //inherit an "array" of dimension Dimension -1 
            template < ut_dim Dimension , class type , 
                template <class...> class STL_container = std :: vector > 
                    class dynamic_vector 
                        : public my_dynamic_vector 
                            < dynamic_vector < decrease(Dimension) , 
                            type , STL_container > , STL_container > {                        
                
                
                    static_assert ( Dimension > 0 , "Dimension should be > 0" ) ;

                    public :
                        typedef std :: array < t_dim , Dimension > Index_t;

                    public :
                        dynamic_vector ( Index_t Lenght = { 0 } ) {
                            std :: array < t_dim , decrease(Dimension) > Other = { 0 } ;
                                for ( auto i = 0 ; i != Other . size () ; i ++ ) {
                                    Other [ i ] = Lenght [ i + 1 ] ;
                                }
                            my_dynamic_vector<
                                dynamic_vector<decrease(Dimension),type,STL_container>,STL_container>
                                    :: resize (Lenght[0],
                                        dynamic_vector<decrease(Dimension),type,STL_container>(Other));

                        };

                    //operators
                    public : childclass & operator[](const t_dim index );
                    public : childclass   operator[](const t_dim index ) const ;
                    public : template < ut_dim Dim > 
                                auto & operator[](const std :: array<t_dim,Dim> index );
                    public : template < ut_dim Dim > 
                                auto   operator[](const std :: array<t_dim,Dim> index ) const ;

                    //functions
                    public : thisclass transpose (const t_dim left=0 , const t_dim right=1) const ;
                    public : Index_t begin() const ;
                    public : Index_t next(const Index_t now ) const ;
                    public : Index_t last() const ;
                    public : Index_t end() const ;
                        
            } ;
            
        }        
    }
}
#define Template template<ut_dim Dimension,class type,template <class...> class STL_container >
#define Class dynamic_vector <Dimension,type,STL_container>  

#include "dynamic_vector_operators.h"
#include "dynamic_vector_functions.h"

#undef Template
#undef Class

#undef motherclass 
#undef childclass
#undef thisclass
