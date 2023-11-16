void memzero(byte* start, int size){
    for(int i = 0; i < size; i++){
        *(start + i) = 0;
    }
}

void memcpy(byte* from, byte* to, int size){
    for(int i = 0; i < size; i++){
        *(to + i) = *(from + i);
    }
}
