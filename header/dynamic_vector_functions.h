
#pragma once

namespace eliastocco {       
    namespace container {    
        namespace dynamic {
        
            //#define Template template<ut_dim Dimension,class type,\
            //    template <class...> class STL_container >\
            //        dynamic_vector <Dimension,type,STL_container>
            
            #define Index_t typename Class::Index_t
             
            Template
                thisclass Class :: transpose (const t_dim left , const t_dim right ) const {

                    if(left==right){return *this;}
                    //std :: cout << "transpose" << std :: endl ;
                    auto e = this->end();
                    auto _e = this->last();
                    for(auto i=0;i<Dimension;++i){
                        _e[i]++;
                    }
                    std :: array < t_dim , Dimension > Lenght = _e;                            
                    Lenght[left] = _e[right];
                    Lenght[right]= _e[left];                            

                    thisclass out (Lenght);           

                    //std :: cout << "out" << std :: endl ;
                    t_dim appo =0;

                    auto b = this->begin();                            
                    auto j = b; //solo per avere il tipo giusto                            
                    //int k = 0 ;                            
                    //std :: cout << "cycle" << std :: endl ;
                    for(auto i=b;i!=e;i=this->next(i)){                            
                        //std :: cout << k ++  << std :: endl ;                                
                        //for(auto kk=0;kk<Dimension;++kk){
                        //    std::cout << i[kk] << ",";
                        //}
                        //std :: cout << std :: endl;                            
                        j=i;
                        j[left]=i[right];
                        j[right]=i[left];
                        //std::swap(j[left],i[right]);                                
                        out[j]=(*this)[i];

                    }

                    return out;

                }
            
            Template
                Index_t Class :: begin() const {                            
                    Index_t index; 
                    index.fill(0);
                    return index;
                }
                        
            Template
                Index_t Class :: next(const Index_t now ) const {

                    auto size=this->size();
                    if(now[0]>=size){                                
                        return this->end();//now
                    }

                    std :: array < t_dim , Dimension -1 > sub_index;
                    for(auto i=0;i<Dimension-1;++i){
                        sub_index[i]=now[i+1];
                    }

                    auto A = (*this)[now[0]];
                    auto a = A.next(sub_index);
                    //auto a = motherclass::operator[](now[0]).next(sub_index);
                    if (a==sub_index){                                
                        if(now[0]==size-1){
                            return this->end();//now
                        }else{
                            Index_t index;
                            index.fill(0);
                            index[0]=now[0]+1;
                            return index;
                        }                                
                    } else {
                        Index_t index;
                        std::copy(a.begin(),a.end(),std::next(index.begin()));
                        index[0]=now[0];
                        return index;
                    }
                }
                        
                Template
                    Index_t Class :: last() const {                        
                        Index_t now ;
                        Index_t last ;
                        Index_t index =this->begin(); 
                        do{
                            last=now;
                            now=index;
                            index = this->next(now);  
                        }while(index!=now);  
                        return last;
                    }
                    
                Template
                    Index_t Class :: end() const {                        
                        Index_t index;
                        index.fill(-1);                 
                        return index;
                    }   
              
              #undef Index_t
        }
    }
}
