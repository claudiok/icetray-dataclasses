{
// loading the needed libraries
gSystem->Load("libicetray.so");
gSystem->Load("libdataclasses.so");
gSystem->Load("liblog4cpp.so");

// making a list and filling it
cout<<"First we make a new TList and fill it with four named objects: "
    <<"n1, n2, n3, n4"<<endl;
TList *list = new TList();
list->Add(new TNamed("n1",""));
list->Add(new TNamed("n2",""));
list->Add(new TNamed("n3",""));
list->Add(new TNamed("n4",""));

// making a new Iter<TObject>
I3Iter<TObject> iter(new I3TCollectionIterator<TObject>(list));

// looping over all the objects in the list and printing the names
cout<<"Then we use the iterator to retrieve the objects and print their names"<<endl;
for(iter.First();!iter.IsDone();iter.Next()){
  cout<<iter.CurrentItem().GetName()<<endl;
}


}
