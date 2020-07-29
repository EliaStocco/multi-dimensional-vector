
#pragma once

namespace eliastocco {       
    namespace container {    
        namespace dynamic {
        
            // class specialization 
            template < class type , template <class...> class STL_container > 
                class dynamic_vector < 1 , type , STL_container > 
                    : public  my_dynamic_vector < type , STL_container > {

                    #define motherclass my_dynamic_vector<type,STL_container>
                    
                        public :
                            typedef std :: array < t_dim ,1> Index_t;

                        public :             
                            dynamic_vector ( std :: array < t_dim , 1 > Lenght = { 0 } ) 
                                : my_dynamic_vector < type , STL_container > ( Lenght ) {}

                        public :
                            Index_t begin() const {
                                Index_t index ;
                                index[0]=0;
                                return index;
                            }

                        public :
                            Index_t last() const {
                                Index_t index ;
                                index[0]=this->size();
                                return index;
                            }

                        public :
                            Index_t end() const {
                                Index_t index ;
                                index[0]=-1;
                                return index;
                            }

                        public :
                            Index_t next(const Index_t now ) const {

                                auto size = this->size();
                                Index_t index ;
                                if (now[0]>=size){ //out of range
                                    index[0]=-1;
                                }else if(now[0]==size-1){ // the last one
                                    index[0]=size-1;
                                }else{
                                    index[0]=now[0]+1; //return the next
                                }

                                return index;

                            }                           

                        public :
                            type & operator[](const t_dim index ){
                                //std :: cout << "type & operator[](const t_dim index ) " << index 
                                //<< std :: endl;   
                                //return motherclass::operator[](index);
                                return motherclass::at(index);
                            }

                        public :
                            type operator[](const t_dim index ) const {
                                //std :: cout << "type operator[](const t_dim index ) const " << index 
                                //<< std :: endl;   
                                //return motherclass::operator[](index);
                                return motherclass::at(index);
                            }

                        public :
                            type & operator[](const Index_t index ){
                                //std :: cout<<"type & operator[](const std :: array < t_dim,1> index ) " 
                                //<< index[0] << std :: endl;   
                                //return motherclass::operator[](index[0]);
                                return motherclass::at(index[0]);
                            }

                        public :
                            type operator[](const Index_t index ) const {
                                //std :: cout << "type operator[](const std :: array < t_dim,1> index ) 
                                //const " << index[0] <<std :: endl;  
                                //return motherclass::operator[](index[0]);
                                return motherclass::at(index[0]);
                            }
                            
                            
                        #undef motherclass  

            };  
        
        }
    }
}
