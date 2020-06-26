float m[11][6];
float l;
byte i,j;
int n;
byte op;
float v[10];
void setup()
{
  Serial.begin(9600);
  Serial.println("  ##&&   ESCUELA MILITAR DE INGENIERIA   &&##  "); 
  Serial.println("         *****************************         ");
  Serial.println(" Sbtte. Log. Milenka Tatiana Gutierrez Delagado ");
  Serial.println("  Sbtte. Ing. Henry Alexander Pacheco Ventura   ");
  Serial.println("       Sbtte. Com. Monica Medina Quisberth      ");
  Serial.println("      Alf. CGON. Luis Guillermo Banda Quispe    ");  
  Serial.println("         *****************************         ");
  Serial.println();
}
void loop ()
{
  op=menu();
  switch(op)
  {
    case 1:
      cDDAT(); //CANTIDAD DE DATOS A TOMAR 
      break;
    case 2:
      pDmD(); //TOMAR DATOS Y DESPLEGAR
      break;
    case 3:
      mF();   //MEDIAS DE FILAS 
      break;
    case 4:
      mC();   // MEDIAS DE COLUMNAS 
      break;
    case 5:
      mMF();  // MAYOR Y MENOR DE VALOR FILAS 
      break;
    case 6:
      mMC();
      break;
    case 7:
      eAF();
      eRF();
      break;
    case 8:
      eAC();
      eRC();
      break;
    case 9:
      eaT();
    break;
  }
}
int menu()
{
  int OPCION;
  Serial.println("|    Menu    |");
  Serial.println("|1|  CANTIDAD DE DATOS A TOMAR  |");
  Serial.println("|2|  TOMAR DATOS Y DESPLEGAR  |");
  Serial.println("|3|  MEDIAS DE FILAS  |");
  Serial.println("|4|  MEDIAS DE COLUMNAS    |");
  Serial.println("|5|  MAYOR Y MENOR DE VALOR FILAS    |");
  Serial.println("|6|  MAYOR Y MENOR DE VALOR DE COLUMNAS|");
  Serial.println("|7|  ERROR ABSOLUTO Y RELATIVO DE FILAS    |");
  Serial.println("|8|  ERROR ABSOLUTO Y RELATIVO DE COLUMNAS    |");
  Serial.println("|9|  ERROR ABSOLUTO Y RELATIVO TOTAL    |");
  Serial.println();
  while(!Serial.available()){}
  OPCION=Serial.readString().toInt();
  return OPCION;
}
void cDDAT()
{
    Serial.println("---------------------------------");
    Serial.println("Ingrese la cantidad de datos a tomar:");
    while(true){
      n = Serial.readString().toInt();
      if(n>0) break;
    }
    Serial.print("N ingresado Exitosamente! n = ");
    Serial.println(n);
    Serial.println("---------------------------------");
  
}
void pDmD()
{

   int i,j;
  for (i=1;i <= n;i+=1) {
    for (j=1;j<=4;j+=1) {
      Serial.write("[");Serial.write(i+48);Serial.write(",");Serial.write(" Sensor ");Serial.write(j+48),Serial.write("]:");
      while (!Serial.available());
      m[i][j] = Serial.parseInt(); Serial.println(m[i][j]); 
      delay(300);   
    }
  }
  
  Serial.println("");
  Serial.print("|#");
  for(byte k=1; k<=4 ; k++)
  {
    Serial.print("|Sensor"); Serial.print(k);
  }
  Serial.println("|");
  Serial.println("----------------------------");
  for(byte i=1;i<=n;i++)
  {
    j=i;
//    delay(1000);
//    l = analogRead(A1);
//    m[i][1]=0.48701298701*l;
//    l = analogRead(A2);
//    m[i][2]=0.48701298701*l; 
//    l = analogRead(A3);
//    m[i][3]=0.48701298701*l; 
//    l = analogRead(A4);
//    m[i][4]=0.48701298701*l;
    Serial.print("|");Serial.print(j);
    Serial.print("| ");Serial.print(m[i][1]);
    Serial.print(" | ");Serial.print(m[i][2]);
    Serial.print(" | ");Serial.print(m[i][3]);
    Serial.print(" | ");Serial.print(m[i][4]);Serial.println("|");
    Serial.println("---------------------------------------");
  }
  Serial.print(" |");
}
void mF()
{
  float mf;
  for(byte i=1; i<=n; i++)
  {
    mf=0.00;
    for(byte j=1; j<=4;j++)
    {
      mf = m[i][j] + mf;
    }
    mf=mf/4;
    Serial.print("MEDIA DE FILA ");Serial.print(i);Serial.print(" ES = ");Serial.println(mf);
    v[i]=mf;
  }
}
void mC()
{
  float mc;
  for(byte j=1; j<=4; j++)
  {
    mc = 0,00;
    for(byte i=1;i<=n; i++)
    {
      mc = mc + m[i][j];
    }
    mc=mc/n;
    Serial.print("MEDIA DEL SENSOR ");Serial.print(j);Serial.print(" ES = ");Serial.println(mc);
    m[n][j]=mc;
  }
}
void mMF()
{
  float mayor,menor;
  for(byte i=1; i<=n;i++)
  {
    mayor = -1000000,00;
    menor =  1000000,00;
    for(byte j=1;j<=4;j++)
    {
      if(m[i][j] > mayor) mayor=m[i][j];
      if(m[i][j] < menor) menor=m[i][j];
    }
    Serial.print("EL MAYOR DE LA FILA ");Serial.print(i);Serial.print("ES=");Serial.println(mayor);
    Serial.print("EL MENOR DE LA FILA");Serial.print(i);Serial.print("ES = ");Serial.println(menor);  
  }
}
void mMC() // menor MAYOR de la columna
{
  float mayor,menor;
  for(byte j=1 ; j<=4 ; j++)
  {
    mayor = 0,00;
    menor = 100,00;
    for(byte i=1 ; i<=n ; i++)
    {
      if(m[i][j]>mayor)
      {
        mayor = m[i][j];
      }
    }
    Serial.print("EL MAYOR DE SENSOR");Serial.print(j);Serial.print("ES = ");Serial.println(mayor);
  }
  for(byte j=1 ; j<=4 ; j++)
  {
    mayor = 0,00;
    menor = 100,00;
    for(byte i=1 ; i<=n ; i++)
    {
      if(m[i][j]<menor)
      {
        menor = m[i][j];
      }
    }
    Serial.print("EL MENOR DE SENSOR");Serial.print(j); Serial.print("ES=");Serial.println(menor);
  }
}
void eAC()
{
  float eac[j];
  for(byte j1; j<=4;j++)
  {
    eac[j]=0.00;
    for(byte i=1; i<=n;i++)
    {
      eac[j]=eac[j] + abs(m[i][j]-m[n][j]);
    }
    eac[j]= eac[j]/n;
    Serial.print("ERROR ABSOLUTO SENSOR");Serial.print(j); Serial.print("ES=");Serial.println(eac[j]);
  }
}
void eRC()
{
  float erc,eac[j];
  for(byte j1; j<=4;j++)
  {
    erc = (eac[j]/m[n][j])*100;
    Serial.print("ERROR RELATIVO SENSOR");Serial.print(j); Serial.print("ES=");Serial.println(erc);
  }
  Serial.println();
}
void eAF()
{
  float eaf[i];
  for(byte i=1;i<=n;i++)
  {
    eaf[i]= 0.00;
    for(byte j1; j<=4;j++)
    {
      eaf[i] = eaf[i] + abs(m[i][j]-v[i]);
    }
    eaf[i]=eaf[i]/4;
    Serial.print(" ERROR ABSOLUTO FILA");Serial.print(i);Serial.print(" ES= ");Serial.println(eaf[i]);
  }
  Serial.println();
}
void eRF()
{
  float erf,eaf[j];
  for(byte i=1;i<=n;i++)
  {
    erf=(eaf[j]/v[i])*100;
    Serial.print("ERROR RELATIVO SENSOR");Serial.print(j); Serial.print("ES=");Serial.println(erf);
  }
  Serial.println();
}
void eaT()
{
  float mt;
  mt = 0.00;
  for(byte i=1; i<=4;i++)
  {
    for(byte j=1; j<=4;j++)
    {
      mt = m[i][j] + mt;
    }
  }
  mt = mt/(n*4);
  float eat,ert;
  eat = 0.00;
  for(byte i=1; i<=4;i++)
  {
    for(byte j=1; j<=4;j++)
    {
      eat = eat+abs(m[i][j]-mt);
    }
  }
  eat = eat/(n*4);
  Serial.print("EL ERROR ABSOLUTO DEL TOTAL ES=");Serial.print(eat);
  ert=eat/mt;
  Serial.print("EL ERROR RELATIVO DEL TOTAL ES=");Serial.println(ert);
}
