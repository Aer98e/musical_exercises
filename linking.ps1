# EnlazarObjetosGPP.ps1

$archivoLista = "list_obj.txt"
$outputExe = ".\bin\main.exe"

# Preguntar si se desea ingresar nuevos archivos
Write-Host "¿Deseas ingresar nuevos archivos .o? (s/n)"
$respuesta = Read-Host

if ($respuesta -eq "s") {
    Write-Host "Ingresa los nombres de los archivos .o separados por espacio:"
    $input_1 = Read-Host
    $objFiles = $input_1.Split(" ")
    # Guardar en el archivo
    Set-Content -Path $archivoLista -Value ($objFiles -join "`n")
}
else {
    # Leer desde el archivo
    if (Test-Path $archivoLista) {
        $objFiles = Get-Content $archivoLista
        $objFiles = $objFiles | ForEach-Object { ".\build\$_" }
    }
    else {
        Write-Host "No se encontró el archivo $archivoLista. Ejecuta el script nuevamente e ingresa los archivos."
        exit
    }
}

# Construir comando g++

$gppCommand = "g++ -g " + ($objFiles -join " ") + " -o $outputExe"

# Mostrar y ejecutar
Write-Host "`nEjecutando:"
Write-Host $gppCommand
Invoke-Expression $gppCommand
