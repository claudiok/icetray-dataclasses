{
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("liblog4cpp.so");

I3Bag *bag = new I3Bag();

TNamed *n1 = new TNamed("Object1","");
TNamed *n2 = new TNamed("Object2","");
TNamed *n3 = new TNamed("Object3","");
TNamed *n4 = new TNamed("Object4","");

if(!bag->AddObject(n1,"key1")){
cout<<"Something went wrong adding n1"<<endl;
}
if(!bag->AddObject(n2,"key2")){
cout<<"Something went wrong adding n2"<<endl;
}
if(!bag->AddObject(n3,"key3")){
cout<<"Something went wrong adding n3"<<endl;
}
if(!bag->AddObject(n4,"key4")){
cout<<"Something went wrong adding n4"<<endl;
}
if(bag->AddObject(0,"key4")){
cout<<"Something went wrong.  Adding 'key4' again should have failed"<<endl;
}
if(bag->HasObject("key1","TNamed")){
cout<<bag->GetObject("key1","TNamed").GetName()<<endl;
}
if(bag->HasObject("key2","TNamed")){
cout<<bag->GetObject("key2","TNamed").GetName()<<endl;
}
if(bag->HasObject("key3","TNamed")){
cout<<bag->GetObject("key3","TNamed").GetName()<<endl;
}
if(bag->HasObject("key4","TNamed")){
cout<<bag->GetObject("key4","TNamed").GetName()<<endl;
}


}
