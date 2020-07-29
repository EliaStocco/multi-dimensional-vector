
#pragma once

namespace eliastocco {       
    namespace container {    
        namespace dynamic {
        
            //#define Class template<ut_dim Dimension,class type,\
            //    template <class...> class STL_container >\
            //        dynamic_vector <Dimension,type,STL_container>
                 
                Template
                    childclass & Class :: operator[](const t_dim index ){
                        //std :: cout << "childclass & operator[](const t_dim index ) "
                        //<< index << std::endl;
                        //return motherclass::operator[](index);
                        return motherclass::at(index);
                    }

                Template
                    childclass Class :: operator[](const t_dim index ) const {
                        //std :: cout << "childclass operator[](const t_dim index ) 
                        //<<index<<std::endl;
                        //return motherclass::operator[](index);
                        return motherclass::at(index);
                    }
    
        
                Template
                    template < ut_dim Dim >
                        auto & Class :: operator[](const std :: array<t_dim,Dim> index ) {
                            //std::cout<< "auto & operator[](const std :: array<t_dim,Dim> index )Dim=" 
                            //<< Dim << std :: endl;

                            if constexpr (Dim>1){

                                std :: array < t_dim , decrease(Dim) > new_index = { 0 } ;
                                for ( auto i = 0 ; i < Dim-1 ; i ++ ) {
                                    new_index [ i ] = index [ i + 1 ] ;
                                }

                                //auto a = motherclass::operator[](index[0]);

                                //return motherclass::operator[](index[0])[new_index];
                                return (motherclass::at(index[0]))[new_index];

                            }else {
                                //std :: cout << "ciao2" << index[0] << std :: endl;
                                return motherclass::at(index[0]);
                            }

                        }

                Template
                    template < ut_dim Dim >
                        auto Class :: operator[](const std :: array<t_dim,Dim> index ) const {
                            //std :: cout << "auto operator[](const std :: array<t_dim,Dim> index ) 
                            //const, Dim=" << Dim << std :: endl;

                            if constexpr (Dim>1){

                                std :: array < t_dim , decrease(Dim) > new_index = { 0 } ;
                                for ( auto i = 0 ; i < Dim-1 ; i ++ ) {
                                    new_index [ i ] = index [ i + 1 ] ;
                                }

                                //std :: cout << "ciao" << index[0] << std :: endl;

                                //auto a = motherclass::operator[](index[0]);

                                //return motherclass::operator[](index[0])[new_index];
                                return (motherclass::at(index[0]))[new_index];

                            }else {
                                //std :: cout << "ciao2" << index[0] << std :: endl;
                                return motherclass::at(index[0]);
                            }

                        }
                            
            //#undef Class
        
        }
    }
}
