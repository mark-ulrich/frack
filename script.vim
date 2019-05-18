function ReplaceAllGetParms(case_sensitive)
  call inputsave()
  let pattern = input('Pattern: ')
  let new = input('Replace With: ')
  call inputrestore()
  call ReplaceAll(pattern, new, a:case_sensitive)  
endfunction

function ReplaceAll(pattern, new, case_sensitive)
  let cmd = "%s/" . a:pattern . "/" . a:new . "/g" . (a:case_sensitive ? "": "i")
  try
    execute cmd
  catch
    echo "ERROR"
  endtry
endfunction

