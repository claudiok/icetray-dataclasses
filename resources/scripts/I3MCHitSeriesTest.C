void I3MCHitSeriesTest()
{
  gSystem->Load("libicetray.so");
  gSystem->Load("libdataclasses.so");

  cout << "Running test" << endl;

  const Float_t x = 6666.6;

  I3MCHit h1, h2;
  h1.Weight(x);
  assert(h1.Weight() == x);
  h2 = h1;
  cout << h1.Weight() << endl;
  cout << h2.Weight() << endl;
  assert(h2.Weight() == x);

  I3MCHit h3(h2);
  assert(h3.Weight() == x);

  I3MCHitSeries hs;

  for (int i=0; i<400; i++) {
    h1.Weight((rand()%2048)*1.112);
    h1.TrackNumber(rand()%2048);
    hs.push_back(h1);
  }
  assert(hs.size()==400);

  for (I3MCHitSeries::iterator iter = hs.begin();
       iter != hs.end();
       iter++) 
    {
      cout << iter->Weight() << endl;
    }

  hs.clear();
  assert(hs.size() == 0);

  cout << "tests passed" << endl;
}



