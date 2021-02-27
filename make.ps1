# remove old files
Remove-Item bin\*
Remove-Item *.exe
Write-Host "Removed old compiled files"

# call make
make

# run main
Push-Location ".\bin"
.\main.exe
Pop-Location