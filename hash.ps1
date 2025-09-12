$baseDir = Get-Location
$sourceDir = Join-Path $baseDir "src"
$hashOutputDir = Join-Path $baseDir "hash"

if (!(Test-Path -Path $hashOutputDir)) {
    New-Item -ItemType Directory -Path $hashOutputDir
}

# Obtener todos los archivos .cpp
$cppFiles = Get-ChildItem -Path $sourceDir -Filter *.cpp -File

foreach ($file in $cppFiles) {
    # Calcular el hash SHA256
    $hash = Get-FileHash -Path $file.FullName -Algorithm SHA256

    # Crear archivo de salida con el mismo nombre pero extensión .txt
    $outputFile = Join-Path $hashOutputDir ($file.BaseName + ".txt")

    # Guardar el hash en el archivo
    $hash.Hash | Out-File -FilePath $outputFile
}

Write-Host "✅ Hashes generados y guardados en: $hashOutputDir"
