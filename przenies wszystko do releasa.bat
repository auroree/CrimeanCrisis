mkdir CrimeanCrisis\Release
mkdir CrimeanCrisis\CrimeanCrisis\Release

copy bin\*.* CrimeanCrisis\Release
copy bin\*.* CrimeanCrisis\CrimeanCrisis\Release

mkdir CrimeanCrisis\Release\models
copy CrimeanCrisis\CrimeanCrisis\models\*.* CrimeanCrisis\Release\models

mkdir CrimeanCrisis\Release\grafiki
copy CrimeanCrisis\CrimeanCrisis\grafiki\*.* CrimeanCrisis\Release\grafiki

mkdir CrimeanCrisis\Release\sound
copy CrimeanCrisis\CrimeanCrisis\sound\*.* CrimeanCrisis\Release\sound
