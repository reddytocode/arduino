float m[11][7];
float l;
byte i,j;
int n;
byte op;
float v[10];
void despliegue(float matx[][7]);

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
      errorReativoColumna();
      break;
  }
}
int menu()
{
  int OPCION;
  Serial.println("");
  Serial.println("|    Menu    |");
  Serial.println("|1|  CANTIDAD DE DATOS A TOMAR  |");
  Serial.println("|2|  TOMAR DATOS Y DESPLEGAR  |");
  Serial.println("|3|  MEDIAS DE FILAS  |");
  Serial.println("|4|  MEDIAS DE COLUMNAS    |");
  Serial.println("|5|  MAYOR Y MENOR DE VALOR FILAS    |");
  Serial.println("|6|  MAYOR Y MENOR DE VALOR DE COLUMNAS|");
  Serial.println("|7|  ERROR ABSOLUTO Y RELATIVO DE COLUMNAS    |");
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
    for (j=1;j<=5;j+=1) {
      Serial.write("n =");Serial.write(i+48);Serial.write(", ");Serial.write(" Sensor ");Serial.write(j+48),Serial.write(" >> ");
      while(true){
        m[i][j] = Serial.parseInt(); 
        if(m[i][j]>0) break;
      }
      Serial.println(m[i][j]); 
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
    Serial.print("|");Serial.print(j);
    Serial.print("| ");Serial.print(m[i][1]);
    Serial.print(" | ");Serial.print(m[i][2]);
    Serial.print(" | ");Serial.print(m[i][3]);
    Serial.print(" | ");Serial.print(m[i][4]);
    Serial.print(" | ");Serial.print(m[i][5]);Serial.println("|");
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
    for(byte j=1; j<=5;j++)
    {
      mf = m[i][j] + mf;
    }
    mf=mf/5;
    Serial.print("MEDIA DE FILA ");Serial.print(i);Serial.print(" ES = ");Serial.println(mf);
    m[i][6] = mf;
  }
}
void mC()
{
  float mc;
  for(byte j=1; j<=5; j++)
  {
    mc = 0,00;
    for(byte i=1;i<=n; i++)
    {
      mc = mc + m[i][j];
    }
    mc=mc/n;
    Serial.print("MEDIA DEL SENSOR ");Serial.print(j);Serial.print(" ES = ");Serial.println(mc);
    m[n+1][j]=mc;
  }
}
void mMF()
{
  float mayor,menor;
  for(byte i=1; i<=n;i++)
  {
    mayor = -1000000,00;
    menor =  1000000,00;
    for(byte j=1;j<=5;j++)
    {
      if(m[i][j] > mayor) mayor=m[i][j];
      if(m[i][j] < menor) menor=m[i][j];
    }
    Serial.print("EL MAYOR DE LA FILA ");Serial.print(i);Serial.print(" ES = ");Serial.println(mayor);
    Serial.print("EL MENOR DE LA FILA ");Serial.print(i);Serial.print(" ES = ");Serial.println(menor);  
  }
}
void mMC() // menor MAYOR de la columna
{
  float mayor,menor;
  for(byte j=1 ; j<=5 ; j++)
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
    Serial.print("EL MAYOR DE SENSOR ");Serial.print(j);Serial.print(" ES = ");Serial.println(mayor);
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
    Serial.print("EL MENOR DE SENSOR ");Serial.print(j); Serial.print(" ES = ");Serial.println(menor);
  }
}
void eAC()
{
  
  float eac[j];
  for(byte j = 1; j<=5;j++)
  {
    Serial.print("media: ");Serial.print(j); Serial.print(" : ");Serial.print(m[n][j]);
    eac[j]=0.00;
    for(byte i=1; i<=n;i++)
    {
      eac[j]=eac[j] + abs(m[i][j]-m[n][j]);
    }
    eac[j]= eac[j]/n;
    Serial.print("ERROR ABSOLUTO SENSOR ");Serial.print(j); Serial.print("ES = ");Serial.println(eac[j]);
  }
}
void eRC()
{
  float erc,eac[j];
  for(byte j1; j<=5;j++)
  {
    erc = (eac[j]/m[n][j])*100;
    Serial.print("ERROR RELATIVO SENSOR ");Serial.print(j); Serial.print(" ES=");Serial.println(erc);
  }
  Serial.println();
}
void errorReativoColumna()
{
  despliegue(m);
  for(int j =1; j <=5; j++){
    float errorabsolutoColumna = 0.0;
    for(int i = 1; i<=n; i++){
      errorabsolutoColumna += abs(m[i][j] - m[n+1][j]);
    }
    errorabsolutoColumna = errorabsolutoColumna/n;
    float media = m[n+1][j];
    float errorRelativo = (errorabsolutoColumna/media) * 100.00;
    
    Serial.print(" ERROR RELATIVO SENSOR ");Serial.print(j);Serial.print(" ES = ");Serial.println(errorabsolutoColumna);
    Serial.print(" ERROR ABSOLUTO SENSOR ");Serial.print(j);Serial.print(" ES = ");Serial.print(errorRelativo);Serial.println("%.");
  }
  
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
  for(byte i=1; i<=n;i++)
  {
    for(byte j=1; j<=5;j++)
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
  Serial.print("EL ERROR ABSOLUTO DEL TOTAL ES = ");Serial.print(eat);
  ert=eat/mt;
  Serial.print("EL ERROR RELATIVO DEL TOTAL ES = ");Serial.println(ert);
}


void despliegue(float matx[][7]) {
  int i,j;
  for (i=1;i <= n+1;i+=1) {
    for (j=1;j<=7;j+=1) {
      Serial.write(" [");Serial.write(i+48);Serial.write(",");Serial.write(j+48),Serial.write("]: ");
      Serial.print(matx[i][j]);Serial.write(" ");
    }
    Serial.println(' ');
  }
}
