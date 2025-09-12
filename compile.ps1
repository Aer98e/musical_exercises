# Rutas
$sourceDir = ".\src"
$includeDir = ".\include"
$buildDir  = ".\build"
$hashDir   = ".\hashes"

# Crear carpetas si no existen
foreach ($dir in @($buildDir, $hashDir)) {
    if (!(Test-Path $dir)) {
        New-Item -ItemType Directory -Path $dir
    }
}

# Obtener archivos .cpp
$cppFiles = Get-ChildItem -Path $sourceDir -Filter *.cpp -File

foreach ($file in $cppFiles) {
    $filePath = $file.FullName
    $fileName = $file.BaseName
    $hashFile = Join-Path $hashDir "$fileName.txt"
    $objectFile = Join-Path $buildDir "$fileName.o"

    # Calcular hash actual
    $currentHash = (Get-FileHash -Path $filePath -Algorithm SHA256).Hash

    # Leer hash anterior si existe
    $previousHash = if (Test-Path $hashFile) { Get-Content $hashFile } else { "" }

    # Comparar hashes
    if ($currentHash -ne $previousHash) {
        Write-Host "🔄 Archivo modificado: $fileName.cpp → Compilando..."

        # Compilar en modo depuración
        $compileCommand = "g++ -c `"$filePath`" -I `"$includeDir`" -g -o `"$objectFile`""
        Invoke-Expression $compileCommand

        # Actualizar hash
        $currentHash | Out-File -FilePath $hashFile -Encoding ASCII
    } else {
        Write-Host "✅ Sin cambios: $fileName.cpp → No se compila"
    }
}

Write-Host "🏁 Proceso terminado. Solo se compilaron archivos modificados."
